// Author: Anna Pinchuk
// Date: 13/04/2023
// Description: This file contains the war game.
// In test driven development, we write the tests first, and then we write the code.
// credit to: course staff for the demo file, and the functions' descriptions.To copilot for helping with the comments.

#pragma ONCE
#include <string>
using namespace std;
namespace ariel
{
  class Game
  {
  private: // Access specifier
    Player player1;
    Player player2;
    std::string log;
    std::string lasturn;
    // The class
  public: // Access specifier
    // Constructor
    Game(Player p1, Player p2);
    // destructor
    ~Game();
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
  };
}