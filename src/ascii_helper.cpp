#include "ascii_helper.hpp"
#include <iostream>

std::string AsciiHelper::getAsciiArt(std::ifstream &file) {

  std::string ascii = "";

  if (file) {
    while (file.good()) {
      std::string tempLine;
      std::getline(file, tempLine);
      tempLine += "\n";
      ascii += tempLine;
    }
  } else {
    ascii = "image not found sorry!";
  }

  return ascii;
}