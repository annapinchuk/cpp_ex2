#pragma ONCE
#include <iostream>
#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
using namespace ariel;
using namespace std;
class Game
{
private: // Access specifier
    Player player1;
    Player player2;
    // The class
public: // Access specifier
    // Constructor
    Game::Game(Player p1, Player p2)
    {
        player1 = p1;
        player2 = p2;
    }
    void Game::playTurn()
    {
        cout << "playTurn" << endl;
    }
    void Game::printLastTurn()
    {
        cout << "printLastTurn" << endl;
    }
    void Game::stacksize()
    {
        cout << "stacksize" << endl;
    }
    void Game::cardesTaken()
    {
        cout << "cardesTaken" << endl;
    }
    void Game::playAll()
    {
        cout << "playAll" << endl;
    }
    void Game::printWiner()
    {
        cout << "printWiner" << endl;
    }
    void Game::printLog()
    {
        cout << "printLog" << endl;
    }
    void Game::printStats()
    {
        cout << "printStats" << endl;
    }
};