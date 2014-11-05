#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <unordered_set>
#include <string>

#include "porter2_stemmer.h"

class Dictionary {
private:
  std::unordered_set<std::string> words_;

public:

  void addWord(const std::string& word) {
    words_.insert(word);  
  };

  bool isPresent(const std::string& word) const {
    if (words_.find(word) != words_.end()) {
      return true;      
    } else {
      return false;
    }
  };

  static void loadDictionary(std::string& file_path,
			     Dictionary& dictionary);
};

#endif    //  DICTIONARY_H_
