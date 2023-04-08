

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
    int drawrate = 0;

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
    int getDrawRate()
    {
        return drawrate;
    }
    string getName()
    {
        return name;
    }
    // Setters
    void addCard(Card card)
    {
        cards.push_back(card);
    }
    bool isPlaying()
    {
        return is_playing;
    }
    void win()
    {
        numwingames++;
    }
};