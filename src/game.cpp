#include "game.hpp"
#include <map>

void Game::start(int &choice) {
  reset();
  std::string hiddenWord = "";

  switch (choice) {
  case 1:
    hiddenWord = "brick";
    break;
  case 2:
    hiddenWord = "drying";
    break;
  case 3:
    hiddenWord = "flyback";
    break;
  }
  hiddenword_ = hiddenWord;
  int maxTries = getMaxTries();
}

void Game::reset() {
  currentTry_ = 1;
  gameIsWon_ = false;
  return;
}

int Game::getMaxTries() const {
  std::map<int, int> wordLengthToMaxTries{{5, 10}, {6, 16}, {7, 20}};
  return wordLengthToMaxTries[hiddenword_.length()];
}

GuessStatus Game::checkGuessValidity(std::string Guess) const {
  if (!isIsogram(Guess)) {
    return GuessStatus::Not_Isogram;
  } else if (!isLowerCase(Guess)) {
    return GuessStatus::Not_Lowercase;
  } else if (Guess.length() != getHiddenWordLength()) {
    return GuessStatus::Wrong_length;
  } else {
    return GuessStatus::OK;
  }
}

BullCowCount Game::submitValidGuess(std::string guess) {

  currentTry_++;
  BullCowCount bullCowCount;
  int wordLength = hiddenword_.length();

  for (int mhwChar = 0; mhwChar < wordLength; mhwChar++) {
    for (int gChar = 0; gChar < wordLength; gChar++) {
      if (guess[gChar] == hiddenword_[mhwChar]) {
        if (mhwChar == gChar) {
          bullCowCount.Bulls++;
        } else {
          bullCowCount.Cows++;
        }
      }
    }
  }
  if (bullCowCount.Bulls == wordLength) {
    gameIsWon_ = true;
  } else {
    gameIsWon_ = false;
  }
  return bullCowCount;
}

bool Game::isIsogram(std::string word) const {
  if (word.length() <= 1) {
    return true;
  }

  std::map<char, bool> letterSeen;

  for (auto letter : word) {
    letter = tolower(letter);
    if (letterSeen[letter]) {
      return false;
    } else {
      letterSeen[letter] = true;
    }
  }
  return true;
}

bool Game::isLowerCase(std::string word) const {
  for (auto letter : word) {
    if (!islower(letter)) {
      return false;
    }
  }
  return true;
}
