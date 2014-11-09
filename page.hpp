#ifndef PAGE_H_
#define PAGE_H_

#include "gumbo.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <iostream>

class Page {
public:
  typedef std::shared_ptr<Page> PagePtr;
  typedef std::unordered_map<std::string, int> StringCounterMap;
  typedef std::shared_ptr<StringCounterMap> StringCounterMapPtr;
private:
  std::string link_;
  std::string html_;
  StringCounterMapPtr words_;
  
public:
  explicit Page(std::string link);

  static void *pull_one_url(void*params_in);

  static void readHTML(std::string& link, std::string& html);

  static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);  

  static std::string cleanText(GumboNode* node);

  void parseHtml(void);
  
  void retrieveWords(std::string& text);

  
  void setHtml(std::string html) {
    html_ = html;
  };

  void search_for_links(GumboNode* node);
  
  StringCounterMapPtr getWords(void) {
    return words_;
  }

  std::string getLink(void) {
    return link_;
  };
  
  std::string getHtml(void) {
    return html_;
  };

};

#endif    //  PAGE_H_
