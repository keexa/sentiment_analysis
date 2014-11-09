#include "reader.hpp"

#include <fstream>

std::vector<std::string> Reader::loadURLs(void) {
  std::ifstream urls_stream(file_path_);
  std::vector<std::string> filenames;

  if (urls_stream.is_open()) {
    std::string filename;

    while (getline(urls_stream, filename)) {
      std::cout << filename << '\n';
      filenames.emplace_back(filename);
    };
    urls_stream.close();  
  };
  return filenames;
};
