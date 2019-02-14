#ifndef GAME_HPP
#define GAME_HPP
#include <vector>
#include <cstdlib>
#include "Card.h"
const int SIZE_DECK = 52;
const int NUM_PLAYERS = 2;
const int SIZE_HAND = SIZE_DECK/NUM_PLAYERS;
class Game
{
    private:
        std::vector<Card> deck;
        std::vector<Card> p1;
        std::vector<Card> p2;
    public:
        Game();
        Game(std::vector<Card>);
        Game(std::vector<Card>, std::vector<Card>, std::vector<Card>);
        template<class RandomIt>
        void random_shuffle( RandomIt first, RandomIt last );
        void play();
        void populateDeck();
        void populatePlayerHands();
        void shuffle();


};

#endif