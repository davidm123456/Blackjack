//
//  Game.cpp
//

#include "Game.h"
#include <iostream>

namespace cs31
{

Game::Game() : mOutcome( NOTYETDECIDED ), mPlayerStood(false)
{
    
}
    
// for cheating purposes
// allows you to create two Players and then force certain
// game play
Game::Game( Player player, Player dealer ) :  mOutcome( NOTYETDECIDED ), mPlayerStood( false ), mDealer( dealer ), mPlayer( player ) 
{
    
}
    
bool Game::playerWon()
{
    return( mOutcome == HUMANPLAYERWON );
}
    
bool Game::playerLost()
{
    return( mOutcome == HUMANPLAYERLOST );
}
    
bool Game::playerTied( )
{
    return( mOutcome == GAMETIED );
}
    
// shuffle the Deck
// send two cards to the Human Player
// send two cards to the Dealer
void Game::deal()
{
	mDeck.shuffleDeck();
	Card c1 = mDeck.dealCard();
	mPlayer.acceptCard(c1);
	Card c2 = mDeck.dealCard();
	mPlayer.acceptCard(c2);
	Card c3 = mDeck.dealCard();
	mDealer.acceptCard(c3);
	Card c4 = mDeck.dealCard();
	mDealer.acceptCard(c4);
}
    
// send one card to the Human Player
void Game::playerHits( )
{
	Card c = mDeck.dealCard();
	mPlayer.acceptCard(c);
}

// the Human Player ends his turn
void Game::playerStands( )
{
    mPlayerStood = true;
}
    
// has the Human Player ended his turn?
bool Game::playerStood() const
{
    return( mPlayerStood );
}

// send one Card to the Dealer
void Game::dealerHits( )
{
    Card c = mDeck.dealCard();
    mDealer.acceptCard( c );
}
    
// the Dealer ends his turn
// so now determine the Game outcome by setting mOutcome correctly
void Game::dealerStands( )
{
	if (dealerHasBlackJack()) {
		if (playerHasBlackJack()) {
			mOutcome = GAMETIED;
		}
		else {
			mOutcome = HUMANPLAYERLOST;
		}
	}
	else {
		if (playerHasBlackJack()) {
			mOutcome = HUMANPLAYERWON;
		}
		else if ((dealerBusted()) && (!playerBusted())) {
			mOutcome = HUMANPLAYERWON;
		}
		else if ((!dealerBusted()) && (playerBusted())) {
			mOutcome = HUMANPLAYERLOST;
		}
		else if (mDealer.handcount() == mPlayer.handcount()) {
			mOutcome = GAMETIED;
		}
		else if (mDealer.handcount() > mPlayer.handcount()) {
			mOutcome = HUMANPLAYERLOST;
		}
		else if (mDealer.handcount() < mPlayer.handcount()) {
			mOutcome = HUMANPLAYERWON;
		}
	}
}
    
// has the Dealer gone over 21?
bool Game::dealerBusted( ) const
{
    bool result = false;
	if (mDealer.handcount() > 21) {
		result = true;
	}
    return( result );
}
    
// has the Human Player gone over 21?
bool Game::playerBusted( ) const
{
    bool result = false;
	if (mPlayer.handcount() > 21) {
		result = true;
	}
    return( result );
}
    
// let the Dealer play his hand
void Game::dealerPlays()
{
    if (!playerBusted())
    {
        int count = 0;
        int dealerCount = 0;
        dealerCount = mDealer.handcount();
        while( dealerCount <= 16 )
        {
            dealerHits();
            dealerCount = mDealer.handcount();
            count = count + 1;
            if (count > Player::MAXCARDS)
                break;
        }
    }
    dealerStands();
}
  
// print out the Game
void Game::display( std::string s  )
{
    display( s, false );
}
    
void Game::display( std::string s , bool allCards )
{
    // when allCards is true  --> show all dealer cards
    // otherwise just show the one turned up dealer card
    // and then display the passed message at the bottom of the screen, if supplied
    using namespace std;
    int dealerCount = mDealer.handcount();
    int playerCount = mPlayer.handcount();
    cout << "DEALER'S HAND:" << endl;
    if (allCards)
    {
        cout << mDealer.toString() << endl;
    }
    else
    {
        cout << mDealer.getCard(0).toString() << endl;
    }
    if (dealerBusted())
    {
        cout << "          --->dealer busted!" << endl;
    }
    else if (allCards)
    {
        cout << "          --->" << dealerCount << endl;
    }
    cout << endl;
    cout << "PLAYER'S HAND:" << endl;
    cout << mPlayer.toString() << endl;
    if (playerBusted())
    {
        cout << "          --->player busted!" << endl;
    }
    else if (allCards)
    {
        cout << "          --->" << playerCount << endl;
    }

    if (s != "")
        cout << s << endl;
}
   
// does the Human Player have BlackJack?
bool Game::playerHasBlackJack( ) const
{
    return( mPlayer.hasBlackJack() );
}
  
// does the Dealer have BlackJack?
bool Game::dealerHasBlackJack( ) const
{
    return( mDealer.hasBlackJack() );
}

    
}
