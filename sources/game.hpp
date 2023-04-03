

#pragma ONCE

namespace ariel
{
  class Game
  {
  private: // Access specifier
    Player player1;
    Player player2;
    // The class
  public: // Access specifier
    // Constructor
    Game(Player p1, Player p2);
    void playTurn();
    void printLastTurn();
    void stacksize();
    void cardesTaken();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
  };
}