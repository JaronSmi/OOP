#ifndef CARD_HPP
#define CARD_HPP
#include <iostream>

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
	public:
		Card(Rank r, Suit s) :data(static_cast<unsigned>(s) << 4 | static_cast<unsigned>(r)){}
			Rank get_rank() const {return static_cast<Rank>(data & 0xf);}
			Suit get_suit() const {return static_cast<Suit>(data >> 4) ;}
	private:
		unsigned char data;

}; 


#endif