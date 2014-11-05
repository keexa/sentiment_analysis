#ifndef READER_H_
#define READER_H_

#include "page.hpp"

#include <memory>
#include <vector>

class Reader {
private:
  std::vector<Page::PagePtr> pages_ = std::vector<Page::PagePtr>();

public:
  void addPage(Page::PagePtr page) {
    pages_.push_back(page);
  }

  std::vector<Page::PagePtr> getPages() {
    return pages_;    
  }
};
 
#endif    //  READER_H_

