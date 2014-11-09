#include "page.hpp"

#include <boost/xpressive/xpressive.hpp>
#include <curl/curl.h>
#include "porter2_stemmer.h"

#include <pthread.h>
#include <cstdio>
#include <iostream>
#include <istream>
#include <vector>
#include <locale>
#include <algorithm>
using namespace boost::xpressive;


static inline bool is_not_alnum_space(char c)
{
  return !(isalpha(c) || isdigit(c) || (c == ' '));
}

bool string_is_valid(const std::string &str)
{
  return find_if(str.begin(), str.end(), is_not_alnum_space) == str.end();
}

Page::Page(std::string link) : link_(link) {
  
};

void Page::retrieveWords(std::string& text) {
  words_ = std::make_shared<StringCounterMap>();

  std::istringstream iss(text);
  std::string word;
  std::locale loc;

  while(iss >> word) {
    Porter2Stemmer::stem(word);

    if ((std::isupper(word[0], loc)) ||// && std::islower(word[1], loc)) ||
	!string_is_valid(word) ||
	std::string::npos != word.find_first_of("0123456789")) {
      continue;
    }

    auto myiterator = words_->find(word);

    if (myiterator != words_->end()) {
      myiterator->second ++ ;
    } else {
      (*words_)[word] = 1;
    }
  }
}

std::string Page::cleanText(GumboNode* node) {
  if (node->type == GUMBO_NODE_TEXT) {
    return std::string(node->v.text.text);
  } else if (node->type == GUMBO_NODE_ELEMENT &&
             node->v.element.tag != GUMBO_TAG_SCRIPT &&
             node->v.element.tag != GUMBO_TAG_STYLE) {
    std::string contents = "";
    GumboVector* children = &node->v.element.children;
    for (unsigned int i = 0; i < children->length; ++i) {
      const std::string text = cleanText((GumboNode*) children->data[i]);
      if (i != 0 && !text.empty()) {
        contents.append(" ");
      }
      contents.append(text);
    }
    return contents;
  } else {
    return "";
  }
}

void Page::search_for_links(GumboNode* node) {
  sregex rex = sregex::compile("(ftp|http|https)://([\\S]+[^<>]*)", sregex::icase );

  if (node->type != GUMBO_NODE_ELEMENT) {
    return;
  }
  GumboAttribute* href;
  if (node->v.element.tag == GUMBO_TAG_A &&
      (href = gumbo_get_attribute(&node->v.element.attributes, "href"))) {
    link_ = href->value;
  }

  GumboVector* children = &node->v.element.children;
  for (unsigned int i = 0; i < children->length; ++i) {
    search_for_links(static_cast<GumboNode*>(children->data[i]));
    match_results<std::string::const_iterator> what;

    if (regex_search(link_, what, rex)) {
      std::string base_url( what[0].first, what[0].second);
      //      std::string query( what[1].first, what[1].second);
            std::cout << base_url << std::endl;
	    //std::cout << query << std::endl;
    }
  }
};

size_t Page::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  ((std::string*)userp)->append((char*)contents, size * nmemb);
  return size * nmemb;
};

struct string_curl {
  char *ptr;
  size_t len;
};

void Page::parseHtml(void) {
  GumboOutput* output = gumbo_parse(html_.c_str());
  //  page->search_for_links(output->root);
  std::string text = cleanText(output->root);
  //  std::cout << text << std::endl;
  retrieveWords(text);
  gumbo_destroy_output(&kGumboDefaultOptions, output);
};



void* Page::pull_one_url(void *params_in) {
  Page* page = (Page*)params_in;
  CURL *curl;
  curl = curl_easy_init();
  //  struct string_curl* sc = new struct string_curl();
  curl_easy_setopt(curl, CURLOPT_URL, page->getLink().c_str());
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
  std::string strin;
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &strin);
  bool res = curl_easy_perform(curl);
  curl_easy_cleanup(curl);
  page->setHtml(strin);
  GumboOutput* output = gumbo_parse(page->getHtml().c_str());
  //  page->search_for_links(output->root);
  std::string text = page->cleanText(output->root);
  //  std::cout << text << std::endl;
  page->retrieveWords(text);
  gumbo_destroy_output(&kGumboDefaultOptions, output);
  

  std::cout << "Size2: " << page->getWords()->size() << std::endl;

  for (auto k : *(page->getWords())) {
    std::cout << k.first << " " << k.second << std::endl;
  }
  return NULL;
};

