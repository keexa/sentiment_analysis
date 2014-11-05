#include "dictionary.hpp"
#include <fstream>

void Dictionary::loadDictionary(std::string& file_path,
				Dictionary& dictionary) {
  std::ifstream dict_stream(file_path);
  
  if (dict_stream.is_open()) {
    std::string word;
    
    while (getline(dict_stream, word)) {
      Porter2Stemmer::stem(word);
      dictionary.addWord(word);
    };
    dict_stream.close();  
  };
}
