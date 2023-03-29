#pragma once
#include <vector>
using namespace std;
#include "card.hpp"
namespace ariel
{
class Player {     // The class
  private:          // Access specifier
    string name;
    vector<Card> cards;
    int cardes_Taken;
    bool is_playing;
  public:           // Access specifier
    // Constructor
    Player(string p_name){ 
      name = p_name;
      cardes_Taken = 0;
      is_playing = true;
    }
    // Default Constructor   
    Player(){ 
      name = "stranger";
      cardes_Taken = 0;
      is_playing = true;
    }    
    int stacksize(){
      return cards.size();
    }
    int cardesTaken(){
      return cardes_Taken;
    }
    void addCard(Card card){
      cards.push_back(card);
    }
};
}