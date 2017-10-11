
#include "../src/ascii_helper.hpp"
#include "catch_main.hpp"

AsciiHelper ascii_helper;

SCENARIO("show the user that the image is not found ", "[getAsciiArt]") {
  WHEN("i try to load the ascii example.txt ") {
    std::ifstream input("example.txt");
    std::string response = ascii_helper.getAsciiArt(input);
    THEN("i return a message that the image is not found") {
      std::string answer = "image not found sorry!";
      REQUIRE(response == answer);
    }
  }
}