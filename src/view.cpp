#include "view.hpp"
#include "ascii_helper.hpp"
#include "game.hpp"
#include <iostream>
#include <sstream>

Game game;
AsciiHelper asciiHelper;

void View::start() {
  bool bPlayAgain = false;
  printIntro();
  do {
    playGame();
    bPlayAgain = askToPlayAgain();
  } while (bPlayAgain);
  printOutro();
}

void View::printIntro() {
  std::cout << "Welcome to Bulls and Cows" << std::endl;
  std::cout << std::endl;

  std::ifstream filePath("src/ascii/cow.txt");
  std::cout << asciiHelper.getAsciiArt(filePath) << std::endl;

  return;
}

void View::printOutro() {
  std::ifstream filePath("src/ascii/thank_you.txt");
  std::cout << asciiHelper.getAsciiArt(filePath) << std::endl;
}

int View::difficulty() {

  std::cout << "Choose your level" << std::endl;
  std::cout << "1 - Easy, ";
  std::cout << "2 - Normal, ";
  std::cout << "3 - Hard : ";

  int choice{0};

  bool check = false;

  do {
    std::string input = "";
    std::getline(std::cin, input);
    std::stringstream stream(input);
    stream >> choice;

    std::cout << "You picked ";

    switch (choice) {
    case 1:
      std::cout << "Easy." << std::endl;
      check = true;
      break;
    case 2:
      std::cout << "Normal." << std::endl;
      check = true;
      break;
    case 3:
      std::cout << "Hard." << std::endl;
      check = true;
      break;
    default:
      std::cout << "a non valid level" << std::endl;
      check = false;
    }
  } while (!check);

  return choice;
}

void View::playGame() {

  int choice = difficulty();
  game.start(choice);

  std::cout << "Can you guess the " << game.getHiddenWordLength();
  std::cout << " letter isogram I'm thinking of?" << std::endl;

  while (!game.isGameWon() && game.getCurrentTry() <= game.getMaxTries()) {

    std::string Guess = getValidGuess();
    BullCowCount bullCowCount = game.submitValidGuess(Guess);

    std::cout << "Bulls = " << bullCowCount.Bulls;
    std::cout << ". Cows = " << bullCowCount.Cows << std::endl;
  }

  printGameSummary();
  return;
}

std::string View::getValidGuess() {
  std::string Guess = "";
  GuessStatus status = GuessStatus::Invalid_Status;
  do {
    int currentTry = game.getCurrentTry();
    std::cout << "Try " << currentTry << " of " << game.getMaxTries();
    std::cout << ". Enter your guess: ";
    std::getline(std::cin, Guess);

    status = game.checkGuessValidity(Guess);
    switch (status) {
    case GuessStatus::Wrong_length:
      std::cout << "Please enter a " << game.getHiddenWordLength()
                << " letter word." << std::endl;
      break;
    case GuessStatus::Not_Isogram:
      std::cout << "Please enter a word without repeating letters."
                << std::endl;
    case GuessStatus::Not_Lowercase:
      std::cout << "Please enter all lowercase letters." << std::endl;
      break;
    default:
      break;
    }
  } while (status != GuessStatus::OK);
  return Guess;
}

bool View::askToPlayAgain() {

  std::cout << "Do you want to play again? (y/n)?" << std::endl;
  std::string response = "";
  std::getline(std::cin, response);
  return (response[0] == 'y') || (response[0] == 'Y');
}

void View::printGameSummary() {
  if (game.isGameWon()) {
    // TODO put ascii image
    std::cout << "Well done - You win!" << std::endl;
  } else {
    // TODO put ascii image
    std::cout << "Better luck next time!" << std::endl;
  }
}