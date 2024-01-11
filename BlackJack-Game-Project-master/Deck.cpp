//
//  Dealer.cpp
//

#include "Deck.h"
#include "RandomNumber.h"
#include <iostream>

namespace cs31
{
    
    Deck::Deck()
    {
        // create all 52 Cards found in a standard Deck
        myCards[ 0 ]  =  Card( ACE, HEARTS );
        myCards[ 1 ]  =  Card( ACE, CLUBS );
        myCards[ 2 ]  =  Card( ACE, DIAMONDS );
        myCards[ 3 ]  =  Card( ACE, SPADES );
        myCards[ 4 ]  =  Card( DEUCE, HEARTS );
        myCards[ 5 ]  =  Card( DEUCE, CLUBS );
        myCards[ 6 ]  =  Card( DEUCE, DIAMONDS );
        myCards[ 7 ]  =  Card( DEUCE, SPADES );
        myCards[ 8 ]  =  Card( THREE, HEARTS );
        myCards[ 9 ]  =  Card( THREE, CLUBS );
        myCards[ 10 ] =  Card( THREE, DIAMONDS );
        myCards[ 11 ] =  Card( THREE, SPADES );
        myCards[ 12 ] =  Card( FOUR, HEARTS );
        myCards[ 13 ] =  Card( FOUR, CLUBS );
        myCards[ 14 ] =  Card( FOUR, DIAMONDS );
        myCards[ 15 ] =  Card( FOUR, SPADES );
        myCards[ 16 ] =  Card( FIVE, HEARTS );
        myCards[ 17 ] =  Card( FIVE, CLUBS );
        myCards[ 18 ] =  Card( FIVE, DIAMONDS );
        myCards[ 19 ] =  Card( FIVE, SPADES );
        myCards[ 20 ] =  Card( SIX, HEARTS );
        myCards[ 21 ] =  Card( SIX, CLUBS );
        myCards[ 22 ] =  Card( SIX, DIAMONDS );
        myCards[ 23 ] =  Card( SIX, SPADES );
        myCards[ 24 ] =  Card( SEVEN, HEARTS );
        myCards[ 25 ] =  Card( SEVEN, CLUBS );
        myCards[ 26 ] =  Card( SEVEN, DIAMONDS );
        myCards[ 27 ] =  Card( SEVEN, SPADES );
        myCards[ 28 ] =  Card( EIGHT, HEARTS );
        myCards[ 29 ] =  Card( EIGHT, CLUBS );
        myCards[ 30 ] =  Card( EIGHT, DIAMONDS );
        myCards[ 31 ] =  Card( EIGHT, SPADES );
        myCards[ 32 ] =  Card( NINE, HEARTS );
        myCards[ 33 ] =  Card( NINE, CLUBS );
        myCards[ 34 ] =  Card( NINE, DIAMONDS );
        myCards[ 35 ] =  Card( NINE, SPADES );
        myCards[ 36 ] =  Card( TEN, HEARTS );
        myCards[ 37 ] =  Card( TEN, CLUBS );
        myCards[ 38 ] =  Card( TEN, DIAMONDS );
        myCards[ 39 ] =  Card( TEN, SPADES );
        myCards[ 40 ] =  Card( JACK, HEARTS );
        myCards[ 41 ] =  Card( JACK, CLUBS );
        myCards[ 42 ] =  Card( JACK, DIAMONDS );
        myCards[ 43 ] =  Card( JACK, SPADES );
        myCards[ 44 ] =  Card( QUEEN, HEARTS );
        myCards[ 45 ] =  Card( QUEEN, CLUBS );
        myCards[ 46 ] =  Card( QUEEN, DIAMONDS );
        myCards[ 47 ] =  Card( QUEEN, SPADES );
        myCards[ 48 ] =  Card( KING, HEARTS );
        myCards[ 49 ] =  Card( KING, CLUBS );
        myCards[ 50 ] =  Card( KING, DIAMONDS );
        myCards[ 51 ] =  Card( KING, SPADES );
        
        myTotalUsed = 0;
    }
    
    // randomly select and return a Card not yet played
    // if there are none, throw a logic_error
    Card Deck::dealCard( )
    {
        Card c;
        int index = -1;
        if (myTotalUsed >= DECKSIZE)
        {
            // no cards left...
            throw std::logic_error( "out of cards" );
        }
        else
        {
            RandomNumber random( 0, 51 );

            do {
                index = random.random();
            } while (myCards[ index ].isInPlay() || myCards[ index ].isDiscarded());
            /// we want the index of something not yet used...
            c = myCards[ index ];
            myCards[ index ].inplay();
            myTotalUsed++;
        }
        
        return( c );
    }
    
    // recycle all the Deck's discarded Cards so they
    // can potentially be redealt at a later time
    // update the number of Cards that are in use
    void Deck::shuffleDeck( )
    {
        for (int i = 0; i < DECKSIZE; i++)
        {
            if (myCards[i].isDiscarded())
            {
                myCards[i].recycle();
            }
        }
        myTotalUsed = 0;
        for (int i = 0; i < DECKSIZE; i++)
        {
            if (myCards[i].isInPlay())
            {
                myTotalUsed = myTotalUsed + 1;
            }
        }
    }
    
    // for testing purposes to see the value of a Deck
    std::string Deck::toString() const
    {
        std::string s = "";
        int totalInPlay = 0, totalDiscarded = 0, totalNotPlayed = 0;
        for (int i = 0; i < DECKSIZE; i++)
        {
            if (myCards[i].isInPlay())
            {
                totalInPlay++;
            }
        }
        for (int i = 0; i < DECKSIZE; i++)
        {
            if (myCards[i].isDiscarded())
            {
                totalDiscarded++;
            }
        }
        for (int i = 0; i < DECKSIZE; i++)
        {
            if (myCards[i].isNotPlayed())
            {
                totalNotPlayed++;
            }
        }
        s += "in play: ";
        s += std::to_string( totalInPlay );
        s += " discarded: ";
        s += std::to_string( totalDiscarded );
        s += " notplayed: ";
        s += std::to_string( totalNotPlayed );
        s += "\n";
        return( s );
    }
    
    void Deck::inplay( Card c )
    {
        for (int i = 0; i < DECKSIZE; i++)
        {
            if (myCards[i] == c)
            {
                myCards[i].inplay();
            }
        }
    }
    
    void Deck::discard( Card c )
    {
        for (int i = 0; i < DECKSIZE; i++)
        {
            if (myCards[i] == c)
            {
                myCards[i].discard();
            }
        }
    }
    
    void Deck::recycle( Card c )
    {
        for (int i = 0; i < DECKSIZE; i++)
        {
            if (myCards[i] == c)
            {
                myCards[i].recycle();
            }
        }
    }
}
