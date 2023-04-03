#pragma ONCE
#include <iostream>
#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
using namespace ariel;
using namespace std;
class Card
{
private:            // Access specifier
    int value;      // 1-13 (1=Ace, 11=Jack, 12=Queen, 13=King)
    int type;       // 1-4 (1=spades, 2=hearts, 3=diamonds, 4=clubs)
    bool is_faceUp; // true if the card is face up, false otherwise

public: // Access specifier
    // Constructor
    Card(int xy, int pl)
    {
        value = xy;
        type = pl;
        is_faceUp = false;
    }
    // Getters
    int getValue()
    {
        return value;
    }
    int getType()
    {
        return type;
    }
    bool getIsFaceUp()
    {
        return is_faceUp;
    }
    // Setters
    void flip()
    {
        is_faceUp = !is_faceUp;
    }
};
