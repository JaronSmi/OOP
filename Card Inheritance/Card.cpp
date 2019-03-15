#include "Card.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, Suit s)
{
	switch (s) {
  		case Clubs: return os << " Clubs ";
  		case Spades: return os << " Spades ";
  		case Hearts: return os << " Hearts ";
  		case Diamonds: return os << " Diamonds ";
  	}
}

std::ostream&
operator<<(std::ostream& os, Rank r)
{
  	switch (r) {
  		case Ace: return os << " Ace ";
  		case Two: return os << " 2 ";
  		case Three: return os << " 3 ";
  		case Four: return os << " 4 ";
  		case Five: return os << " 5 ";
  		case Six: return os << " 6 ";
  		case Seven: return os << " 7 ";
  		case Eight: return os << " 8 ";
  		case Nine: return os << " 9 ";
  		case Ten: return os << " 10 ";
  		case Jack: return os << " Jack ";
  		case Queen: return os << " Queen ";
 		case King: return os << " King ";
  	}
}

std::ostream&
operator<<(std::ostream& os, Color c)
{
  return os << (c == Black ? "Black" : "Red");
}


std::ostream&
operator<<(std::ostream& os, StandardCard const& c)
{
  return os << c.rank << c.suit;
}

std::ostream&
operator<<(std::ostream& os, JokerCard const& c)
{
  return os << c.color;
}

void StandardCard::print(std::ostream& os) const
{
	os  << *this;
}

void JokerCard::print(std::ostream& os) const
{
	os << *this;
}

std::ostream& operator<<(std::ostream& os, Card const& c)
{
	c.print(os);
	return os;
}

std::ostream& operator<<(std::ostream& os, Deck const& d)
{
	int count = 0;

	for (Card const* c : d)
	{
		os << *c << " ";
		if(count == 12)
		{
			os << std::endl;
			count = 0;
		}
		else{
			++count;
		}
	}

	return os;
}
