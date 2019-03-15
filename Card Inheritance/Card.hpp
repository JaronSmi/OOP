#include <cassert>
#include <iosfwd>
#include <stdexcept>

enum Suit
{
	Spades,
	Clubs,
	Diamonds,
	Hearts
};

enum Rank 
{
	Ace,
	One,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King
};

enum Color
{
	Black,
	Red
};

struct Card
{
	enum Type
	{
		Standard,
		Joker
	};

	Card(Type t) : type(t);

	virtual void print(std::ostream& os) const = 0;
	virtual Color get_color() const = 0;
	Type type;
}

struct StandardCard : Card 
{
	StandardCard(Rank r, Suit s) : Card(Standard), rank(r), suit(s){}

	void print(std::ostream& os) const override;

	Color get_color() const override{
		return static_cast<Color>(suit > Diamonds);
	}

	Rank rank;
	Suit suit;

};

struct JokerCard : Card
{
	JokerCard(Color c) : Card(Joker), color(c){}

	void print(std::ostream& os) const override;


	Color get_color() const override{
		return color;
	}

	Color color;
};

struct Deck : std::deque<Card*>
{
	using std::deque<Card*>::deque;
};

std::ostream& operator<<(std::ostream& os, Suit s);
std::ostream& operator<<(std::ostream& os, Rank r);
std::ostream& operator<<(std::ostream& os, Color c);
std::ostream& operator<<(std::ostream& os, StandardCard const& c);
std::ostream& operator<<(std::ostream& os, JokerCard const& c);
std::ostream& operator<<(std::ostream& os, Card const& c);
std::ostream& operator<<(std::ostream& os, Deck const& d);
