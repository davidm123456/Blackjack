//
//  Hand.cpp
//

#include "Player.h"
#include <iostream>

namespace cs31
{

Player::Player( ) : myNumberOfCards(0) // no Cards dealt yet
{

}
  
// for testing purposes
std::string Player::toString() const
{
    std::string s = "";
    for (int i = 0; i < myNumberOfCards; i++)
    {
        s += myCards[ i ].toString();
    }
    return( s );
}
 
// add this Card to the Player's hand
void Player::acceptCard(Card c)
{
    // is there space left in the array to hold this card?
    // place the card into the array myCards and
    // update the number of cards counter value
	if (myNumberOfCards < MAXCARDS) {
		myCards[myNumberOfCards] = c;
		myNumberOfCards++;
	}
    // if not, throw a logic_error
	else {
		throw std::logic_error("maximum number of cards allowed is 12");
	}
}
    
// acquire the card at the position indicated
// otherwise, throw a logic_error
Card Player::getCard( int position ) const
{
	Card c;
	if ((position >= 0) && (position <= (myNumberOfCards - 1))) {
		c = myCards[position];
	}
	else {
		throw std::logic_error("index out of range");
	}
    return( c );
}
    
// trivial getter
int Player::cardCount() const
{
    return( myNumberOfCards );
}
    
// the point value of the Cards in this Player's hand
// Aces will count as 1 unless the hand is soft
// which allows for an Ace to also potentially be
// treated as 11.  This alternate total is calculated
// by the operation alternativeHandcount()
int  Player::handcount( ) const
{
    int total = 0;
    for (int i = 0; i < myNumberOfCards; i++)
    {
        Card c = myCards[ i ];
        total = total + c.count( );
    }
    if (handcountIsSoft( total ))
    {
        total = alternativeHandcount();
    }
    return( total );
}
    
// A hand is soft if it has an Ace that can be
// treated as either a point value of 1 or 11
// In other words, the total needs to be 11 or less
// and an Ace needs to be found in the Player's hand
bool Player::handcountIsSoft( int total ) const
{
    bool result = false;
    // room for an Ace to be 1 or 11
    if (total <= 11)
    {
        for (int i = 0; i < myNumberOfCards; i++)
        {
            Card c = myCards[ i ];
            if (c.getFace() == Face::ACE)
            {
                result = true;
            }
        }
    }
    return( result );
}
    
// treat one Ace as 11 points, not 1
int  Player::alternativeHandcount( ) const
{
    int total = 0;
    bool handledOneAce = false;
    for (int i = 0; i < myNumberOfCards; i++)
    {
        Card c = myCards[ i ];
        if (c.getFace() == Face::ACE && !handledOneAce)
        {
            total = total + 11;
            handledOneAce = true;
        }
        else
        {
            total = total + c.count( );
        }
    }
    return( total );
}
    
// do we have BlackJack?
bool Player::hasBlackJack( ) const
{
    bool result = false;
    if (myNumberOfCards == 2 && handcount() == 21)
    {
        result = true;
    }
    return( result );
}
    
}
