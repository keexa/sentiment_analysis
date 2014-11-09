#ifndef URL_READER_H_
#define URL_READER_H_

#include "page.hpp"
#include "reader.hpp"

#include <memory>
#include <vector>

class UrlReader : public Reader {

public:
  UrlReader(std::string& file_path): Reader(file_path) {
  };

  void loadPages(void) override;

  void readURLs(std::vector<std::string>& urls);  

  virtual ~UrlReader() {
  }
};
 
#endif    //  URL_READER_H_

