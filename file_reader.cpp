#include "file_reader.hpp"

#include <stdio.h>
#include <curl/curl.h>
#include <string>
#include <iostream>
#include <fstream>

#include <thread>

void FileReader::loadPages(void) {
  std::vector<std::string> urls = loadURLs();
  readFromFiles(urls);
}

void FileReader::loadFile(std::string file_path, size_t i){//, Page::PagePtr page) { 
  std::ifstream file_stream(file_path);
  file_stream.seekg(0, std::ios::end);
  size_t size = file_stream.tellg();
  std::string buffer(size, ' ');
  file_stream.seekg(0);
  file_stream.read(&buffer[0], size); 
  file_stream.close();
  Page::PagePtr p = getPages()[i];
  p->retrieveWords(buffer);
}

void FileReader::readFromFiles(std::vector<std::string>& urls) {
    size_t numt = urls.size();
    size_t i = 0; 

    std::vector<std::thread> threads;
    for (auto& url : urls) {            
      Page::PagePtr page = std::make_shared<Page>(url);
      addPage(page);
      threads.push_back(std::thread(&FileReader::loadFile, this, url, i));//, page));
      i ++;
    }
 
    /* now wait for all threads to terminate */ 
    for (auto & t : threads) {
      t.join();
    } 
};

