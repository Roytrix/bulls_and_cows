#ifndef VIEW_H_
#define VIEW_H_

#include <string>

class View {
public:
  void start();
  void printIntro();
  void printOutro();
  int difficulty();
  void playGame();
  std::string getValidGuess();
  bool askToPlayAgain();
  void printGameSummary();
};

#endif // VIEW_H_