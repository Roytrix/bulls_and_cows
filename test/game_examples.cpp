#include "../src/ascii_helper.hpp"
#include "../src/game.hpp"
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

Game game;

SCENARIO("scale the maximum tries with chosen difficulty", "[getMaxTries]") {
  GIVEN("Easy difficulty") {
    int input = 1;
    game.start(input);
    int response = game.getMaxTries();
    THEN("it returns 10 try") {
      int answer = 10;
      REQUIRE(response == answer);
    }
  }
  GIVEN("Normal difficulty") {
    int input = 2;
    game.start(input);
    int response = game.getMaxTries();
    THEN("it returns 16 try") {
      int answer = 16;
      REQUIRE(response == answer);
    }
  }

  GIVEN("Hard difficulty") {
    int input = 3;
    game.start(input);
    int response = game.getMaxTries();
    THEN("it returns 20 try") {
      int answer = 20;
      REQUIRE(response == answer);
    }
  }
}
