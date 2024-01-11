//
//  Game.h
//

#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Deck.h"
#include <string>

namespace cs31
{
    // the possible Game Outcomes that are possible
    enum OUTCOME
    {
        NOTYETDECIDED,   // not yet known
        HUMANPLAYERWON,  // Human has won
        HUMANPLAYERLOST, // Dealer has won
        GAMETIED         // Push
    };
    
    class Game
    {
    public:
        Game( );
        // allows for cheating by supplying both
        // the player's hand and the dealer's hand
        Game( Player player, Player dealer );
    
        // shuffle the Deck
        // send two Cards to the Human Player
        // send two Cards to the Dealer
        void deal( );
        // let the Dealer play his hand
        void dealerPlays();

        // the Human Player wants another Card
        void playerHits( );
        // the Human Player ends his turn
        void playerStands( );
        // has the Human Player ended his turn?
        bool playerStood( ) const;
    
        // the Dealer wants another Card
        void dealerHits( );
        // the Dealer ends his turn
        // determine the Game OUTCOME value
        void dealerStands( );

        // has the Human Player busted?
        bool playerBusted( ) const;
        // has the Dealer busted?
        bool dealerBusted( ) const;
    
        // did the Human Player win?
        bool playerWon( );
        // did the HumanPlayer lose?
        bool playerLost( );
        // did the HumanPlayer tie the Dealer?
        bool playerTied( );
    
        // does the Human Player have BlackJack?
        bool playerHasBlackJack( ) const;
        // does the Dealer have BlackJack?
        bool dealerHasBlackJack( ) const;
    
        void display( std::string message );
        void display( std::string message, bool allCards );
    private:
        OUTCOME mOutcome;  // the current outcome of the Game
        bool mPlayerStood; // did the Human Player end his turn?
    
        Deck   mDeck;      // the Deck used by this Game
        Player mDealer;    // the Human Player
        Player mPlayer;    // the dealer is another Player
    };
    
}

#endif
