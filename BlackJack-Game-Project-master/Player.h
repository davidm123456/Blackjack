//
//  Player.h
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Card.h"


namespace cs31
{
    
    class Player
    {
    public:
        Player( );
        
        // add a Card to this Player's hand
        void acceptCard( Card c );
        // return one of the Player's Cards
        // if the index is out of range, throw a logic_error
        Card getCard( int index ) const;
        
        
        // how many Cards are in this Player's hand?
        int  cardCount( ) const;
        // what is the total value of the Cards in this
        // Player's hand?
        int  handcount( ) const;
        // does this Player have BlackJack?
        bool hasBlackJack( ) const;
    
        // for testing purposes
        std::string toString( ) const;

        static const int MAXCARDS=12;
        // in BlackJack, you can't have more than 12
        // cards without busting...
        // 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3 ---> Busted!
    
        // is this Player's hand soft because it has
        // an Ace whose value is being used as 1
        // rather than 11?
    private:
        bool handcountIsSoft( int total ) const;
        // if this Player's hand is soft,
        // interpreting the Ace with a different value
        // will give an alternate count
        int  alternativeHandcount( ) const;
    
        // the Cards in this Player's hand stored in an
        // array named myCards
        Card myCards[ MAXCARDS ];
        // a counter which tracks how many of elements in
        // the array myCards are being used
        int  myNumberOfCards;
    };
    
    
}

#endif 
