

using namespace std;
#include "card.hpp"
#include "player.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
using namespace ariel;
class Player
{        // The class
private: // Access specifier
    string name;
    vector<Card> cards;
    int cardes_Taken;
    bool is_playing;
    int id = 0;
    int numwingames = 0;
    int numdraw = 0;
    int numgames = 0;

public: // Access specifier
    // Constructor
    Player::Player(string p_name)
    {
        name = p_name;
        cardes_Taken = 0;
        is_playing = false;
        id++;
        vector<Card> cards;
    }
    // Default Constructor
    Player::Player()
    {
        id++;
        name = "stranger" + to_string(id); // unique name
        cardes_Taken = 0;
        is_playing = false;
        vector<Card> cards;
    }
    // destructor
    Player::~Player()
    {
        this->cardes_Taken = 0;
        this->cards.clear();
        cout << "Player " << name << " is out of the game" << endl;
    }
    // Getters
    int removecard()
    {
        if (cards.size() == 0)
        {
            return 0;
        }
        else
        {
            Card card = cards.back();
            cards.pop_back();
            return card.getValue();
        }
    }
    int stacksize()
    {
        return cards.size();
    }
    int cardesTaken()
    {
        return cardes_Taken;
    }
    int getNumWin()
    {
        return numwingames;
    }
    int getDraw()
    {
        return numdraw;
    }
    int getNumGames()
    {
        return numgames;
    }
    string getName()
    {
        return name;
    }
    bool isPlaying()
    {
        return is_playing;
    }
    // Setters
    void addCard(Card card)
    {
        cards.push_back(card);
    }
    void setPlaying()
    {
        is_playing = !is_playing;
    }
    void addWin()
    {
        numwingames++;
    }
    void addDraw()
    {
        numdraw++;
    }
    void addGame()
    {
        numgames++;
    }
};