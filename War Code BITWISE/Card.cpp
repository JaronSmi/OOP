#include "Card.h"

// CARD.CPP

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
    os << card.get_rank() << card.get_suit();
    return os;
}