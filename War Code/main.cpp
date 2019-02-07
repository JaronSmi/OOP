#include <iostream>
#include <vector>
#include "Card.h"
#include <algorithm>
#include <random>


const int SIZE_DECK = 52;
const int SIZE_HAND = 26;





int main(int argc, char const *argv[])
{	
	//sets deck and shuffles for game.
	std::vector<Card> deckOf;
	populateDeck(deckOf);
	std::vector<Card>::iterator start = deckOf.begin();
	std::vector<Card>::iterator end = deckOf.begin();
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(deckOf), std::end(deckOf), rng);
	//sets players and gives cards in alternating order to players
	
	std::vector<Card> player1;
	std::vector<Card> player2;
	std::vector<Card>::iterator cards1 = player1.begin();
	std::vector<Card>::iterator cards2 = player2.begin();
	for (unsigned int i = 0; i < deckOf.size(); i = i + 2)
	{
		
		player1.insert(cards1, deckOf[i]);
		player2.insert(cards2, deckOf[1+i]);
        cards1 = player1.begin();
        cards2 = player2.begin();

	}

	for(std::vector<Card>::iterator tester = player2.begin(); tester < player2.end(); ++tester){
		std::cout << *tester << " \n";
	}

	//plays game
	play(player1, player2);
	std::cout << "DONE";

	
	
}



