#ifndef READER_H_
#define READER_H_

#include "page.hpp"

#include <memory>
#include <vector>
#include <string>

class Reader {
private:
  std::vector<Page::PagePtr> pages_ = std::vector<Page::PagePtr>();
  std::string file_path_;

public:
  virtual ~Reader(void) {};

  virtual void loadPages(void) = 0;

  std::vector<std::string> loadURLs();

  Reader(std::string& file_path) {
    file_path_ = file_path;    
  }

  std::string getFilePath(void) {
    return file_path_;
  }

  
  void addPage(Page::PagePtr page) {
    pages_.push_back(page);
  }

  std::vector<Page::PagePtr> getPages() {
    return pages_;    
  }
};
 
#endif    //  READER_H_

