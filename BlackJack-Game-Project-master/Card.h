//
//  Card.h
//

#ifndef CARD_H
#define CARD_H

#include <string>

namespace cs31
{
  
    // the lifecycle of a Card: NOTPLAYED, INPLAY, DISCARDED
    enum Cycle
    {
        INPLAY,     // a dealt card that is held by a player
                    // and in use in a game
        DISCARDED,  // a played card that can be recycled
        NOTPLAYED   // a fresh card that has not yet been
                    // played
    };
    
    // the Suits of a standard 52 card deck
    enum Suit
    {
        HEARTS, DIAMONDS, CLUBS, SPADES
    };
    // the Faces of a standard 52 card deck
    enum Face
    {
        ACE=1, DEUCE=2, THREE=3, FOUR=4, FIVE=5, SIX=6, SEVEN=7, EIGHT=8, NINE=9, TEN=10, JACK=11, QUEEN=12, KING=13
    };
    
    // a class that represents a playing card from a
    // standard 52 card deck
    class Card
    {
    public:
        // ACE of HEARTS by default....
        Card( Face f=ACE, Suit s=HEARTS );
    
        // what is this card's Face value?
        Face getFace( ) const;
        // what is this card's Suit value?
        Suit getSuit( ) const;
        // is this card in play?
        bool isInPlay( ) const;
        // mark this card as being in play
        void inplay( );
        // is this card discarded?
        bool isDiscarded( ) const;
        // mark this card as being discarded
        void discard( );
        // is this card not yet played?
        bool isNotPlayed( ) const;
        // mark this card as being available to be replayed
        void recycle( );      

        // what is the numerical value of this Card
        // in the BlackJack game?
        int  count( ) const;
        // pretty print this Card in a stringified form
        // as in : "Ace of Hearts"
        std::string toString() const;
        
        // are the two Card parameters equal?
        friend bool operator==( const Card& c1, const Card& c2 );
    private:
        Face  myFace;  // this Card's Face value
        Suit  mySuit;  // this Card's Suit value
        Cycle myCycle; // this Card's lifecycle value
    };

}

#endif 
