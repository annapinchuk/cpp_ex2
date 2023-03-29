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
Game game(p1, p2);
// tests for card constructor
TEST_CASE("card")
{
    CHECK_NOTHROW(Card card(1, 1));
}

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