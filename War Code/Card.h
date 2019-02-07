#ifndef CARD_HPP
#define CARD_HPP
#include <iostream>
#include <vector>
#include <cstdlib>

// CARD.H FILE
enum Suit
{
	HEARTS , DIAMONDS , SPADES , CLUBS, SIZE_SUIT
};

enum Rank
{
	TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE, SIZE_RANK	
};

class Card
 {
 	private:
 		Suit suit;
 		Rank rank;
 	public:
 		Card();
 		Card(Rank, Suit);
 		void setRank(Rank r);
 		void setSuit(Suit s);
 		Rank getRank();
 		Suit getSuit();
		friend std::ostream& operator<< (std::ostream& stream, const Rank& rank);
		friend std::ostream& operator<< (std::ostream& stream, const Suit& suit);
		friend std::ostream& operator<< (std::ostream& stream, Card& card);
 }; 
 
template<class RandomIt>
void random_shuffle( RandomIt first, RandomIt last );
void play(std::vector<Card>&, std::vector<Card>&);
void populateDeck(std::vector<Card>&);

#endif