#include "Card.h"

// CARD.CPP
Card::Card()
{

}

Card::Card(Rank r, Suit s)
{
	rank = r;
	suit = s;
}

void Card::setSuit(Suit s)
{
	suit = s;
}

void Card::setRank(Rank r)
{
	rank = r;
}

Suit Card::getSuit()
{
	return suit;
}

Rank Card::getRank()
{
	return rank;
}

void play(std::vector<Card>& p1, std::vector<Card>& p2)
{   
    if (p1.empty() == true && p2.empty() == true)
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
        if(p1Card->getRank() > p2Card->getRank())
        {   
            Card temp = p1[p1.size()];
            p1.insert(p1.begin(), temp);
            temp = p2[p2.size()];
            p1.insert(p1.begin(), temp);
            p2.pop_back();
            std::cout << "Player 1 won round \n";
            play(p1,p2);
        }
        else if(p2Card->getRank() > p1Card->getRank())
        {   
            Card temp = p2[p2.size()];
            p2.insert(p2.begin(), temp);
            temp = p1[p1.size()];
            p2.insert(p2.begin(), temp);
            p1.pop_back();
            std::cout << "Player 2 won round \n";
            play(p1,p2);
        }
        else
        {
            p2.pop_back();
            p1.pop_back();
            std::cout << "WAR!!";
            play(p1, p2);


        }

    }
        
}

void populateDeck(std::vector<Card> &deck)
{
    std::cout << "\nWe're in Here now\n";
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

std::ostream& operator<< (std::ostream& os, const Rank& rank)
{
    switch(rank)
    {
        case ACE:
            os << "ACE OF";
            break;
        case TWO:
            os << "TWO OF";
            break;
        case THREE:
            os << "THREE OF";
            break;
        case FOUR:
            os << "FOUR OF";
            break;
        case FIVE:
            os << "FIVE OF";
            break;
        case SIX:
            os << "SIX OF";
            break;
        case SEVEN:
            os << "SEVEN OF";
            break;
        case EIGHT:
            os << "EIGHT OF";
            break;
        case NINE:
            os << "NINE OF";
            break;
        case TEN:
            os << "TEN OF";
            break;
        case JACK:
            os << "JACK OF";
            break;
        case QUEEN:
            os << "QUEEN OF";
            break;
        case KING:
            os << "KING OF";
            break;

    }
    return os;
}
std::ostream& operator<< (std::ostream& os, const Suit& suit)
{
    switch (suit)
    {
        case HEARTS:
            os << " HEARTS";
            break;
        case CLUBS:
            os << " CLUBS";
            break;
        case DIAMONDS:
            os << " DIAMONDS";
            break;
        case SPADES:
            os << " SPADES";
            break;
    }
    return os;
}
std::ostream& operator<< (std::ostream& os, Card& card)
{
    os << card.getRank() << card.getSuit();
    return os;
}