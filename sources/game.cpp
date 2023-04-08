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
    string log;
    string lasturn;

 // The class
public: // Access specifier
    // Constructor
    Game::Game(Player p1, Player p2)
    {
        log = "";
        lasturn = "";
        player1 = p1;
        player2 = p2;
        vector<Card> all;
        // create cards
        for (int i = 0; i < 14; i++)
        {
            all.push_back(Card(i, 1));
            all.push_back(Card(i, 2));
            all.push_back(Card(i, 3));
            all.push_back(Card(i, 4));
        }
        // shuffle cards
        srand(time(NULL)); // seed random number generator
        for (int i = 0; i < 52; i++)
        {
            int j = rand() % 52;              // random index
            Card temp = all[(unsigned int)i]; // cast to unsigned int to avoid warning
            all[(unsigned int)i] = all[(unsigned int)j];
            all[(unsigned int)j] = temp;
        }
        // give cards to players
        for (int i = 0; i < 26; i++)
        {
            player1.addCard(all[i]);
            player2.addCard(all[i + 26]);
        }
    }
    void Game::playTurn()
    {
        int v1 = this->player1.removecard();
        int v2 = this->player2.removecard();
        // check if one of the players has no cards
        if (v1 == 0 || v2 == 0)
        {
            return this->printWiner();
        }
        // check if the cards are equal
        else if (v1 == v2)
        {
        }
        // check if the card is ace
        else if (v1 == 1 && v2 != 2)
        {
        }
        else if (v1 != 2 && v2 == 1)
        {
        }
        else if (v1 > v2)
        {
        
        }
        // v1 < v2
        else
        {
           
        }
        cout << "playTurn" << endl;
    }
    // print last turn
    void Game::printLastTurn()
    {

        cout << this->lasturn << endl;
    }
    // play all turns
    void Game::playAll()
    {
        for (int i = 0; i < 5; i++)
        {
            this->playTurn();   
        }
        cout << "playAll" << endl;
    }
    // print the winner
    void Game::printWiner()
    {   
        if (this->player1.stacksize() > this->player2.stacksize())
        {
            cout << this->player1.getName() << " is the winner!" << endl;
        }
        else if (this->player1.stacksize() < this->player2.stacksize())
        {
            cout << this->player2.getName() << " is the winner!" << endl;
        }
        else
        {
            cout << "It's a tie!" << endl;
        }
        cout << "printWiner" << endl;
    }
    // print the log
    void Game::printLog()
    {
        cout << this->log << endl;
    }
    void Game::printStats()
    {
        cout << "printStats" << endl;
    }
};