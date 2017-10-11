#ifndef ASCII_HELPER_H_
#define ASCII_HELPER_H_

#include <fstream>
#include <string>

class AsciiHelper {
public:
  std::string getAsciiArt(std::ifstream &file);
};

#endif // ASCII_HELPER_H_
