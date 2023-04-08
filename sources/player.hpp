#pragma once
#include <vector>
using namespace std;
#include "card.hpp"
namespace ariel
{
  class Player
  {        // The class
  private: // Access specifier
    string name;
    vector<Card> cards;
    int cardes_Taken;
    bool is_playing;
    int id;
    int numwingames;
    int drawrate;

  public: // Access specifier
    // Constructor
    Player(string p_name);
    // Default Constructor
    Player();
    // Getters
    int stacksize();
    int removecard();
    string getName();
    int cardesTaken();
    void addCard(Card card);
    // Setters
    bool isPlaying();
  };
}