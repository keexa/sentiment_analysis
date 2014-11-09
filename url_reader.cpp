#include "url_reader.hpp"


#include <pthread.h>
#include <stdio.h>
#include <pthread.h>
#include <curl/curl.h>
#include <string>
#include <iostream>
#include <fstream>

void UrlReader::loadPages(void) {
  std::vector<std::string> urls = loadURLs();
  readURLs(urls);
}

void UrlReader::readURLs(std::vector<std::string>& urls) {
    curl_global_init(CURL_GLOBAL_ALL);
    size_t numt = urls.size();
    pthread_t tid[numt];
    int error;
    size_t i = 0; 
    for (auto& url : urls) {            
      Page::PagePtr page = std::make_shared<Page>(url);
      addPage(page);
      error = pthread_create(&tid[i],
			     NULL, /* default attributes please */ 
			     &(Page::pull_one_url),
			     (void*)page.get());
      if (0 != error) {
	fprintf(stderr, "Couldn't run thread number %d, errno %d\n", i, error);
      } else {	
	fprintf(stderr, "Thread %d, gets %s\n", i, urls[i].c_str());
      }
      i ++;
    }
 
    /* now wait for all threads to terminate */ 
    for (int i = 0; i < numt; i++) {
      error = pthread_join(tid[i], NULL);
      fprintf(stderr, "Thread %d terminated\n", i);
    } 
};

