#include "Card.h"
#include "Game.hpp"
#include <algorithm>
#include <random>
//default constructor, initializes deck and player hands
Game::Game()
{
    populateDeck();
    populatePlayerHands();
}

//sets deck to given vector, makes hand accordingly
Game::Game(std::vector<Card> deckOf)
{
    for (auto iter:deckOf)
    {
        deck.insert(deck.begin(), iter);
    }
    populatePlayerHands();
}

//sets deck and hands to given values
Game::Game(std::vector<Card> deckOf, std::vector<Card> play1, std::vector<Card> play2)
{
    for (auto iter:deckOf)
    {
        deck.insert(deck.begin(), iter);
    }

    for (auto iter:play1)
    {
        play1.insert(play1.begin(), iter);
    }

    for (auto iter:play2)
    {
        play2.insert(play2.begin(), iter);
    }
}


void Game::populatePlayerHands()
{   
    shuffle();
    //splits cards into hands for game
    std::vector<Card>::iterator cards1 = p1.begin();
	std::vector<Card>::iterator cards2 = p2.begin();
    for (unsigned int i = 0; i < deck.size() - 1; i = i + 2)
	{
        p1.insert(cards1, deck[i]);
		p2.insert(cards2, deck[1+i]);
        cards1 = p1.begin();
        cards2 = p2.begin();
	}
}




void Game::play()
{   
    if (p1.empty() ==true && p2.empty() == true)
    {
        std::cout << " DRAW! ";
        return;
    }
    //if player 1 runs out of cards
    else if(p1.empty() == true)
    {
        std::cout << "PLAYER TWO WINS!";
        return;
    }
    //if player 2 runs out of cards
    else if(p2.empty() == true)
    {   
        std::cout << "PLAYER ONE WINS!";
        return;
    }

    //plays the game
    else
    {
        std::vector<Card>::iterator p1Card = p1.begin();
        std::vector<Card>::iterator p2Card = p2.begin();

        //if Player 1's card has a higher rank, p1 gets both cards
        if(p1Card->get_rank() > p2Card->get_rank())
        {   
            Card temp = p1[p1.size()];
            p1.insert(p1.begin(), temp);
            temp = p2[p2.size()];
            p1.insert(p1.begin(), temp);
            p2.pop_back();
            play();
        }
        else if(p2Card->get_rank() > p1Card->get_rank())
        {   
            Card temp = p2[p2.size()];
            p2.insert(p2.begin(), temp);
            temp = p1[p1.size()];
            p2.insert(p2.begin(), temp);
            p1.pop_back();
            play();
        }
        else
        {
            p2.pop_back();
            p1.pop_back();
            play();


        }

    }
        
}

void Game::populateDeck()
{
	std::vector<Card>::iterator startPtr = deck.begin();
	std::vector<Card>::iterator endPtr = deck.end();
	for(int a = 0; a < SIZE_RANK; ++a)
	{
		for(int b = 0; b < SIZE_SUIT; ++b)
		{
			deck.insert(startPtr, Card(static_cast<Rank>(a), static_cast<Suit>(b)));
            startPtr = deck.begin();
		}
	}
}

void Game::shuffle()
{
    auto rng = std::default_random_engine{};
    std::shuffle(std::begin(deck), std::end(deck), rng);
}