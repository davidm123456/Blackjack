//
//  Card.cpp
//

#include "Card.h"

namespace cs31
{
    // by default, a Card is not yet played
    Card::Card( Face f, Suit s ) : myFace( f ), mySuit( s ), myCycle( NOTPLAYED )
    {

    }

    // trivial getter
    cs31::Face Card::getFace( ) const
    {
        return( myFace );
    }
    
    // trivial getter
    cs31::Suit Card::getSuit( ) const
    {
        return( mySuit );
    }
    
    // trivial getter
    bool Card::isInPlay( ) const
    {
        return( myCycle == INPLAY );
    }
    
    // trivial getter
    bool Card::isDiscarded( ) const
    {
        return( myCycle == DISCARDED );
    }
    
    // trivial getter
    bool Card::isNotPlayed( ) const
    {
        return( myCycle == NOTPLAYED );
    }
    
    // trivial lifecycle setter
    void Card::discard( )
    {
        myCycle = DISCARDED;
    }
    
    // trivial lifecycle setter
    void Card::recycle()
    {
        myCycle = NOTPLAYED;
    }
    
    // trivial lifecycle setter
    void Card::inplay()
    {
        myCycle = INPLAY;
    }

    // return true when the two Card parameters have the
    // same Face and Suit value
    bool operator==( const Card& c1, const Card& c2 )
    {
       return( c1.getFace() == c2.getFace() && c1.getSuit() == c2.getSuit() );
    }
    
    // toString() stringifies this Card, as in:
    // "Ace of Hearts"
    std::string Card::toString() const
    {
        std::string s = "";
		switch (myFace) {
		case ACE:
			s += "Ace";
			break;
		case DEUCE:
			s += "Deuce";
			break;
		case THREE:
			s += "Three";
			break;
		case FOUR:
			s += "Four";
			break;
		case FIVE:
			s += "Five";
			break;
		case SIX:
			s += "Six";
			break;
		case SEVEN:
			s += "Seven";
			break;
		case EIGHT:
			s += "Eight";
			break;
		case NINE:
			s += "Nine";
			break;
		case TEN:
			s += "Ten";
			break;
		case JACK:
			s += "Jack";
			break;
		case QUEEN:
			s += "Queen";
			break;
		case KING:
			s += "King";
		}
		s += " of ";
		switch (mySuit) {
		case HEARTS:
			s += "Hearts";
			break;
		case DIAMONDS:
			s += "Diamonds";
			break;
		case CLUBS:
			s += "Clubs";
			break;
		case SPADES:
			s += "Spades";
			break;
		}
        return( s );
    }

    // count() returns the value of this card in the
    // BlackJack game
    int  Card::count( ) const
    {
        int result = 0;
		switch (myFace) {
		case ACE:
			result += 1;
			break;
		case DEUCE:
			result += 2;
			break;
		case THREE:
			result += 3;
			break;
		case FOUR:
			result += 4;
			break;
		case FIVE:
			result += 5;
			break;
		case SIX:
			result += 6;
			break;
		case SEVEN:
			result += 7;
			break;
		case EIGHT:
			result += 8;
			break;
		case NINE:
			result += 9;
			break;
		case TEN:
			result += 10;
			break;
		case JACK:
			result += 10;
			break;
		case QUEEN:
			result += 10;
			break;
		case KING:
			result += 10;
		}
        return( result );
    }
}
