

#pragma ONCE

namespace ariel
{
  class Game
  {
  private: // Access specifier
    Player player1;
    Player player2;
    string log;
    string lasturn;
    // The class
  public: // Access specifier
    // Constructor
    Game(Player p1, Player p2);
    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
  };
}