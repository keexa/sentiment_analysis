#include <string>
#include <vector>
#include <iostream>

#include "analyzer.hpp"
#include "reader.hpp"
#include "url_reader.hpp"
#include "file_reader.hpp"
#include "dictionary.hpp"

int main(int argc, char **argv) {
  std::string urls_file(argv[1]);
  std::string positive_words_file(argv[2]);
  std::string negative_words_file(argv[3]);
  std::cout << urls_file << std::endl;
  Dictionary* positive_words = new Dictionary();
  Dictionary* negative_words = new Dictionary();
  Dictionary::loadDictionary(positive_words_file, *positive_words); 
  Dictionary::loadDictionary(negative_words_file, *negative_words);  
#if 0
  Reader* reader = new UrlReader(urls_file);
  reader->loadPages();

  for (auto& p : reader->getPages()) {
    Analyzer anal(p, positive_words, negative_words);  
    anal.run();    
  }
  delete reader;
#endif

  Reader* reader = new FileReader(urls_file);
  reader->loadPages();

  for (auto& p : reader->getPages()) {
    Analyzer anal(p, positive_words, negative_words);  
    anal.run();    
  }
  delete reader;


}
