#include "analyzer.hpp"

void Analyzer::run(void) {
  size_t pos = 0;
  size_t neg = 0;

  for (auto& wordMap : *(page_->getWords())) {
    std::string word = wordMap.first;      
    bool isPositive = positiveWords_->isPresent(word);
      
    if (isPositive) {
      pos ++;
    }

    bool isNegative = negativeWords_->isPresent(word);     
      
    if (isNegative) {
      neg ++;
    }
  }    
  size_t tot = pos + neg;

  float percentuage = (pos * 100.0f) / (pos + neg);
  std::cout << percentuage << std::endl;
};
