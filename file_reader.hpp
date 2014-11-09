#ifndef FILE_READER_H_
#define FILE_READER_H_

#include "page.hpp"
#include "reader.hpp"

#include <memory>
#include <vector>

class FileReader : public Reader {
public:
  FileReader(std::string& file_path): Reader(file_path) {
  };
  ~FileReader(void) {
  };
  virtual void loadPages(void);

private:
  void readFromFiles(std::vector<std::string>& urls);  

  void loadFile(std::string file_path, size_t i);
};
 
#endif    //  FILE_READER_H_

