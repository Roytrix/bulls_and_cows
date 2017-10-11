#ifndef GAME_H_
#define GAME_H_

#include <string>

struct BullCowCount {
  int Bulls = 0;
  int Cows = 0;
};

enum class GuessStatus {
  Invalid_Status,
  OK,
  Not_Isogram,
  Wrong_length,
  Not_Lowercase
};

class Game {
public:
  Game() { reset(); }
  void start(int &choice);
  void reset();
  int getMaxTries() const;
  int getCurrentTry() const { return currentTry_; }
  int getHiddenWordLength() const { return hiddenword_.length(); }
  bool isGameWon() const { return gameIsWon_; }
  GuessStatus checkGuessValidity(std::string) const;
  BullCowCount submitValidGuess(std::string);

private:
  std::string hiddenword_;
  int currentTry_;
  bool gameIsWon_;
  bool isIsogram(std::string) const;
  bool isLowerCase(std::string) const;
};

#endif // GAME_H_