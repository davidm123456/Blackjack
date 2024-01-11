//
//  Dealer.h
//

#ifndef DECK_H
#define DECK_H

#include <string>
#include "Card.h"


namespace cs31
{
    
    class Deck
    {
    public:
        Deck();
    
        // provide a Card that has not yet been played
        Card  dealCard( );
        // recycle all the discarded Cards so that they
        // can be dealt at a later time, if needed by the
        // Game
        // update the number of Cards that are in use
        void  shuffleDeck( );
        // for testing purposes, stringify this Deck
        std::string toString() const;
        // mark this Deck's Card c as being in play
        void inplay( Card c );
        // mark this Deck's Card c as being discarded
        void discard( Card c );
        // mark this Deck's Card c as being recycled
        void recycle( Card c );
    
    private:
        // by default, this Deck will have 52 cards
        static const int DECKSIZE = 52;
        // the 52 Cards in this Deck will be stored in spots
        // 0-51 of the array of Card named myCards
        Card  myCards[ DECKSIZE ];
        // how many of this Deck's Cards have been used?
        // once the totalUsed reaches 52, we know we are out
        // of Cards
        int   myTotalUsed;
    };
    
    
}

#endif 
