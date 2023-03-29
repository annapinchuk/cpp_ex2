// Author: Anna Pinchuk
// Date: 29/03/2023
// Description: This file contains the tests for the war game.
// In test driven development, we write the tests first, and then we write the code.
// credit to: course staff for the demo file, and the functions' descriptions.To copilot for helping with the comments.

#include "doctest.h"
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;
using namespace doctest;
// tests for  player constructors
TEST_CASE("player1")
{
    CHECK_NOTHROW(Player p1("anna"));
}
TEST_CASE("player2")
{
    CHECK_NOTHROW(Player p2("eden"));
}
TEST_CASE("player3")
{
    CHECK_NOTHROW(Player p3("eden")); // same name
}
TEST_CASE("player4")
{
    CHECK_NOTHROW(Player p4 = Player()); // default constructor
}
Player p1("anna");
Player p2("eden");
Player p3 = Player();
// test for game constructor
TEST_CASE("game")
{
    CHECK_NOTHROW(Game game(p1, p2));
    CHECK_THROWS_AS(Game game(p1, p2), invalid_argument);
    CHECK_THROWS_AS(Game game(p1, p3), invalid_argument);
}
// tests for card constructor
TEST_CASE("card")
{
    CHECK_NOTHROW(Card card(1, 1));
}
TEST_CASE("card exception")
{
    CHECK_THROWS_AS(Card card(14, 1), invalid_argument);
    CHECK_THROWS_AS(Card card(1, 5), invalid_argument);
}
vector<Card> cards;

// shuffle cards
void shuffle_cards()
{
    srand(time(NULL)); // seed random number generator
    for (int i = 0; i < 52; i++)
    {
        int j = rand() % 52;                // random index
        Card temp = cards[(unsigned int)i]; // cast to unsigned int to avoid warning
        cards[(unsigned int)i] = cards[(unsigned int)j];
        cards[(unsigned int)j] = temp;
    }
}

TEST_CASE("fanctional game")
{
    // create cards
    for (int i = 0; i < 14; i++)
    {
        cards.push_back(Card(i, 1));
        cards.push_back(Card(i, 2));
        cards.push_back(Card(i, 3));
        cards.push_back(Card(i, 4));
    }

    shuffle_cards();
    // add cards to players
    for (int i = 0; i < 26; i++)
    {
        p1.addCard(cards[(unsigned int)i]); // cast to unsigned int to avoid warning
        p2.addCard(cards[(unsigned int)i + 26]);
    }
    CHECK(p1.stacksize() == 26);
    CHECK(p2.stacksize() == 26);
    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    CHECK(p1.isPlaying() == false);
    CHECK(p2.isPlaying() == false);
    // play game
    Game game(p1, p2);
    CHECK(p1.isPlaying() == true);
    CHECK(p2.isPlaying() == true);
    CHECK_NOTHROW(game.playAll()); // play all turns
}
Game game(p1, p2);
// tests for functions
TEST_CASE("playTurn")
{
    CHECK_NOTHROW(game.playTurn());
}
TEST_CASE("printLastTurn")
{
    CHECK_NOTHROW(game.printLastTurn());
}
TEST_CASE("stacksize")
{
    CHECK_NOTHROW(game.stacksize());
}
TEST_CASE("cardesTaken")
{
    CHECK_NOTHROW(game.cardesTaken());
}
TEST_CASE("playAll")
{
    CHECK_NOTHROW(game.playAll());
}
TEST_CASE("printWiner")
{
    CHECK_NOTHROW(game.printWiner());
}
TEST_CASE("printLog")
{
    CHECK_NOTHROW(game.printLog());
}
TEST_CASE("printStats")
{
    CHECK_NOTHROW(game.printStats());
}
