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

enum Color
{
	BLACK, RED
};

class StandardCard
{
	public:
		Card(Rank r, Suit s) :data(static_cast<unsigned>(s) << 4 | static_cast<unsigned>(r)){}
			Rank get_rank() const {return static_cast<Rank>(data & 0xf);}
			Suit get_suit() const {return static_cast<Suit>(data >> 4) ;}
	private:
		unsigned char data;

}; 

class JokerCard
{
	public:
		JokerCard(Color c): color(c){}
		Color getColor(){return color;}
	private:
		Color color;
};

union PlayingCardData
{
	PlayingCardData(Rank rank, Suit suit):sc(rank, suit);
	PlayingCardData(Color color):jc(color);

	StandardCard sc;
	JokerCard jc;
};

enum PlayingCardKind
{
	Joker, Standard
}

class PlayingCard
{
	public:
  PlayingCard(Rank r, Suit s)
    : tag(Standard), data(r, s)
  { }

  PlayingCard(Color c)
    : tag(Joker), data(c)
  { }

  bool is_standard() const { 
    return tag == Standard;
  }

  bool is_joker() const { 
    return tag == Joker;
  }

  StandardCard get_as_standard() const {
    assert(is_standard());
    return data.sc;
  }

  Rank get_rank() const {
    assert(is_standard());
    return data.sc.get_rank();
  }

  Suit get_suit() const { 
    assert(is_standard());
    return data.sc.get_suit();
  }

  JokerCard get_as_joker() const {
    assert(is_joker());
    return data.jc;
  }

  Color get_color() const { 
    assert(is_joker());
    return data.jc.get_color();
  }

private:
  PlayingCardKind tag;
  PlayingCardData data;

};

#endif