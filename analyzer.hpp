#ifndef ANALYZER_H_
#define ANALYZER_H_

#include "page.hpp"
#include "analyzer.hpp"
#include "dictionary.hpp"

#include <iostream>

class Analyzer {

private:
  Dictionary* negativeWords_;
  Dictionary* positiveWords_;
  Page::PagePtr page_;

public:
  Analyzer(Page::PagePtr page, Dictionary* positiveWords, Dictionary* negativeWords) {
    negativeWords_ = negativeWords;
    positiveWords_ = positiveWords;
    page_ = page;
  }
  
  void run(void);
};

#endif    //  ANALYZER_H_
