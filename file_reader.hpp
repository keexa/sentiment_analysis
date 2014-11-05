#ifndef FILE_READER_H_
#define FILE_READER_H_

#include "page.hpp"

#include <memory>
#include <vector>

class FileReader : Reader {
public:
  std::vector<std::string> loadFiless(std::string& urls_file);

  void readFiles(std::vector<std::string>& urls);  
};
 
#endif    //  FILE_READER_H_

