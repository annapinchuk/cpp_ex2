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
    int numgames;

  public: // Access specifier
    // Constructor
    Player(string p_name);
    // Default Constructor
    Player();
    // destructor
    ~Player();
    // Getters
    int stacksize();
    int getNumWin();
    Card removecard();
    int getDraw();
    int getNumGames();
    string getName();
    int cardesTaken();
    void addCard(Card card);
    bool isPlaying();
    // Setters
    void setPlaying();
    void addCardsTaken(int num);
    void addWin();
    void addDraw();
    void addGame();
  };
}