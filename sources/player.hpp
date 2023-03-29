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
    int id = 0;

  public: // Access specifier
    // Constructor
    Player(string p_name)
    {
      name = p_name;
      cardes_Taken = 0;
      is_playing = false;
      id++;
    }
    // Default Constructor
    Player()
    {
      id++;
      name = "stranger" + to_string(id); // unique name
      cardes_Taken = 0;
      is_playing = false;
    }
    // Getters
    int stacksize()
    {
      return cards.size();
    }
    int cardesTaken()
    {
      return cardes_Taken;
    }
    void addCard(Card card)
    {
      cards.push_back(card);
    }
    // Setters
    bool isPlaying()
    {
      return is_playing;
    }
  };
}