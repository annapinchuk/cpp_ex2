// Author: Anna Pinchuk
// Date: 13/04/2023
// Description: This file contains the war game.
// In test driven development, we write the tests first, and then we write the code.
// credit to: course staff for the demo file, and the functions' descriptions.To copilot for helping with the comments.

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
        this->player1.addGame();
        this->player2.addGame();
        this->player1.setPlaying();
        this->player2.setPlaying();
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
    // destructor
    Game::~Game()
    {
        this->player1.setPlaying();
        this->player2.setPlaying();
        cout << "Game is over" << endl;
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
            this->player1.addDraw();
            this->player2.addDraw();
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
            this->player1.addWin();
            cout << this->player1.getName() << " is the winner!" << endl;
        }
        else if (this->player1.stacksize() < this->player2.stacksize())
        {
            this->player2.addWin();
            cout << this->player2.getName() << " is the winner!" << endl;
        }
        else
        {
            cout << "It's a tie!" << endl;
        }
    }
    // print the log
    void Game::printLog()
    {
        cout << this->log << endl;
    }
    void Game::printStats()
    {
        cout << this->player1.getName() << " has " << (this->player1.getNumWin() / this->player1.getNumGames()) << " win rate, " << this->player1.cardesTaken() << " cards won, " << this->player1.getDraw() << " number of draws, " << (this->player1.getDraw() / (26 * this->player1.getNumGames())) << " drew rate" << endl;
        cout << this->player2.getName() << " has " << (this->player2.getNumWin() / this->player2.getNumGames()) << " win rate, " << this->player2.cardesTaken() << " cards won, " << this->player2.getDraw() << " number of draws, " << (this->player2.getDraw() / (26 * this->player2.getNumGames())) << " drew rate" << endl;
        cout << "printStats" << endl;
    }
};