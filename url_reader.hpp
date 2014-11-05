#ifndef URL_READER_H_
#define URL_READER_H_

#include "page.hpp"
#include "url_reader.hpp"

#include <memory>
#include <vector>

class UrlReader : Reader {

public:
  std::vector<std::string> loadURLs(std::string& urls_file);

  void readURLs(std::vector<std::string>& urls);  
};
 
#endif    //  URL_READER_H_

