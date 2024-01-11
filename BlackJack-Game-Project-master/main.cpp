//
//  main.cpp
//

#include <iostream>
#include <string>
#include <cassert>
#include "Card.h"
#include "Deck.h"
#include "Game.h"
#include "Player.h"
//void clearScreen();

bool startsWith(std::string data, std::string prefix)
{
	bool result = false;
	if (data.rfind(prefix, 0) == 0) {
		// data starts with prefix
		result = true;
	}
	return(result);
}

int main()
{

	using namespace cs31;
	using namespace std;
	
	// test for card class
	Card c1(Face::ACE, Suit::HEARTS);
	assert(startsWith(c1.toString(), "Ace of Hearts"));
	assert(c1.count() == 1);
	Card c2(Face::ACE, Suit::DIAMONDS);
	assert(startsWith(c2.toString(), "Ace of Diamonds"));
	assert(c2.count() == 1);
	Card c3(Face::ACE, Suit::CLUBS);
	assert(startsWith(c3.toString(), "Ace of Clubs"));
	assert(c3.count() == 1);
	Card c4(Face::ACE, Suit::SPADES);
	assert(startsWith(c4.toString(), "Ace of Spades"));
	assert(c4.count() == 1);
	Card c5(Face::DEUCE, Suit::HEARTS);
	assert(startsWith(c5.toString(), "Deuce of Hearts"));
	assert(c5.count() == 2);
	Card c6(Face::THREE, Suit::HEARTS);
	assert(startsWith(c6.toString(), "Three of Hearts"));
	assert(c6.count() == 3);
	Card c7(Face::FOUR, Suit::HEARTS);
	assert(startsWith(c7.toString(), "Four of Hearts"));
	assert(c7.count() == 4);
	Card c8(Face::FIVE, Suit::HEARTS);
	assert(startsWith(c8.toString(), "Five of Hearts"));
	assert(c8.count() == 5);
	Card c9(Face::SIX, Suit::HEARTS);
	assert(startsWith(c9.toString(), "Six of Hearts"));
	assert(c9.count() == 6);
	Card c10(Face::SEVEN, Suit::HEARTS);
	assert(startsWith(c10.toString(), "Seven of Hearts"));
	assert(c10.count() == 7);
	Card c11(Face::EIGHT, Suit::HEARTS);
	assert(startsWith(c11.toString(), "Eight of Hearts"));
	assert(c11.count() == 8);
	Card c12(Face::NINE, Suit::HEARTS);
	assert(startsWith(c12.toString(), "Nine of Hearts"));
	assert(c12.count() == 9);
	Card c13(Face::TEN, Suit::HEARTS);
	assert(startsWith(c13.toString(), "Ten of Hearts"));
	assert(c13.count() == 10);
	Card c14(Face::JACK, Suit::HEARTS);
	assert(startsWith(c14.toString(), "Jack of Hearts"));
	assert(c14.count() == 10);
	Card c15(Face::QUEEN, Suit::HEARTS);
	assert(startsWith(c15.toString(), "Queen of Hearts"));
	assert(c15.count() == 10);
	Card c16(Face::KING, Suit::HEARTS);
	assert(startsWith(c16.toString(), "King of Hearts"));
	assert(c16.count() == 10);

	// test for deck class
	Deck deck;
	deck.shuffleDeck();
	for (int i = 1; i <= 52; i++)
		deck.dealCard();
	// all the cards have been dealt...
	try
	{
		Card card = deck.dealCard();
		card.toString();
		assert(false);
	}
	catch (logic_error &) {
		assert(true);
	}

	// test for player class
	Player p;
	Card c(Face::ACE, Suit::DIAMONDS);
	Card d(Face::TEN, Suit::CLUBS);
	Card e(Face::THREE, Suit::SPADES);
	Card f(Face::EIGHT, Suit::HEARTS);

	assert(p.handcount() == 0);
	assert(p.hasBlackJack() == false);
	assert(p.cardCount() == 0);
	p.acceptCard(c);
	assert(p.handcount() == 11);
	assert(p.hasBlackJack() == false);
	assert(p.cardCount() == 1);
	assert(p.getCard(0) == c);
	p.acceptCard(d);
	assert(p.handcount() == 21);
	assert(p.hasBlackJack() == true);
	assert(p.getCard(1) == d);
	// getCard throws logic_error when index is out of range
	try
	{
		p.getCard(20);
		assert(false);
	}
	catch (logic_error &)
	{
		assert(true);
	}
	try
	{
		p.getCard(-20);
		assert(false);
	}
	catch (logic_error &)
	{
		assert(true);
	}
	// maximum number of cards allowed is 12
	p.acceptCard(e);
	p.acceptCard(f);
	p.acceptCard(c);
	p.acceptCard(d);
	p.acceptCard(e);
	p.acceptCard(f);
	p.acceptCard(c);
	p.acceptCard(d);
	p.acceptCard(e);
	p.acceptCard(f);
	// acceptCard throws logic_error with the 13th card
	try
	{
		p.acceptCard(c);
		assert(false);
	}
	catch (logic_error &)
	{
		assert(true);
	}

	// test for game class
	p = Player();
	Player dealer;
	Game g(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == true);
	assert(g.playerWon() == false);
	assert(g.playerLost() == false);
	assert(g.playerHasBlackJack() == false);
	assert(g.dealerHasBlackJack() == false);

	p = Player();
	p.acceptCard(c);
	p.acceptCard(d);
	dealer = Player();
	dealer.acceptCard(e);
	dealer.acceptCard(f);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == false);
	assert(g.playerWon() == true);
	assert(g.playerLost() == false);
	assert(g.playerHasBlackJack() == true);
	assert(g.dealerHasBlackJack() == false);

	Card ace(Face::ACE, Suit::HEARTS);
	Card deuce(Face::DEUCE, Suit::HEARTS);
	Card three(Face::THREE, Suit::HEARTS);
	Card four(Face::FOUR, Suit::HEARTS);
	Card five(Face::FIVE, Suit::HEARTS);
	Card six(Face::SIX, Suit::HEARTS);
	Card seven(Face::SEVEN, Suit::HEARTS);
	Card eight(Face::EIGHT, Suit::HEARTS);
	Card ten(Face::TEN, Suit::HEARTS);
	// tie
	p = Player();
	p.acceptCard(ten);
	p.acceptCard(seven);
	dealer = Player();
	dealer.acceptCard(ten);
	dealer.acceptCard(seven);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == true);
	assert(g.playerWon() == false);
	assert(g.playerLost() == false);
	assert(g.playerHasBlackJack() == false);
	assert(g.dealerHasBlackJack() == false);
	// tie & both 21
	p = Player();
	p.acceptCard(ace);
	p.acceptCard(deuce);
	p.acceptCard(eight);
	dealer = Player();
	dealer.acceptCard(ten);
	dealer.acceptCard(six);
	dealer.acceptCard(five);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == true);
	assert(g.playerWon() == false);
	assert(g.playerLost() == false);
	assert(g.playerHasBlackJack() == false);
	assert(g.dealerHasBlackJack() == false);
	// tie & both blackjack
	p = Player();
	p.acceptCard(ace);
	p.acceptCard(ten);
	dealer = Player();
	dealer.acceptCard(ace);
	dealer.acceptCard(ten);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == true);
	assert(g.playerWon() == false);
	assert(g.playerLost() == false);
	assert(g.playerHasBlackJack() == true);
	assert(g.dealerHasBlackJack() == true);
	// player win & player blackjack
	p = Player();
	p.acceptCard(ace);
	p.acceptCard(ten);
	dealer = Player();
	dealer.acceptCard(ten);
	dealer.acceptCard(seven);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == false);
	assert(g.playerWon() == true);
	assert(g.playerLost() == false);
	assert(g.playerHasBlackJack() == true);
	assert(g.dealerHasBlackJack() == false);
	// player win
	p = Player();
	p.acceptCard(ten);
	p.acceptCard(seven);
	p.acceptCard(ace);
	dealer = Player();
	dealer.acceptCard(ten);
	dealer.acceptCard(seven);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == false);
	assert(g.playerWon() == true);
	assert(g.playerLost() == false);
	assert(g.playerHasBlackJack() == false);
	assert(g.dealerHasBlackJack() == false);
	// player win
	p = Player();
	p.acceptCard(ace);
	p.acceptCard(deuce);
	p.acceptCard(seven);
	dealer = Player();
	dealer.acceptCard(ten);
	dealer.acceptCard(six);
	dealer.acceptCard(ace);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == false);
	assert(g.playerWon() == true);
	assert(g.playerLost() == false);
	assert(g.playerHasBlackJack() == false);
	assert(g.dealerHasBlackJack() == false);
	// player win & player 21
	p = Player();
	p.acceptCard(ace);
	p.acceptCard(deuce);
	p.acceptCard(eight);
	dealer = Player();
	dealer.acceptCard(ten);
	dealer.acceptCard(six);
	dealer.acceptCard(ace);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == false);
	assert(g.playerWon() == true);
	assert(g.playerLost() == false);
	assert(g.playerHasBlackJack() == false);
	assert(g.dealerHasBlackJack() == false);
	// player win & player 21
	p = Player();
	p.acceptCard(ten);
	p.acceptCard(seven);
	p.acceptCard(ace);
	p.acceptCard(three);
	dealer = Player();
	dealer.acceptCard(ten);
	dealer.acceptCard(seven);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == false);
	assert(g.playerWon() == true);
	assert(g.playerLost() == false);
	assert(g.playerHasBlackJack() == false);
	assert(g.dealerHasBlackJack() == false);
	// player win & dealer busted
	p = Player();
	p.acceptCard(ace);
	p.acceptCard(deuce);
	dealer = Player();
	dealer.acceptCard(ten);
	dealer.acceptCard(six);
	dealer.acceptCard(six);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == true);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == false);
	assert(g.playerWon() == true);
	assert(g.playerLost() == false);
	assert(g.playerHasBlackJack() == false);
	assert(g.dealerHasBlackJack() == false);
	// player win & player 21 & dealer busted
	p = Player();
	p.acceptCard(ten);
	p.acceptCard(seven);
	p.acceptCard(four);
	dealer = Player();
	dealer.acceptCard(ten);
	dealer.acceptCard(six);
	dealer.acceptCard(six);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == true);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == false);
	assert(g.playerWon() == true);
	assert(g.playerLost() == false);
	assert(g.playerHasBlackJack() == false);
	assert(g.dealerHasBlackJack() == false);
	// player lost & dealer blackjack
	p = Player();
	p.acceptCard(ten);
	p.acceptCard(seven);
	dealer = Player();
	dealer.acceptCard(ace);
	dealer.acceptCard(ten);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == false);
	assert(g.playerWon() == false);
	assert(g.playerLost() == true);
	assert(g.playerHasBlackJack() == false);
	assert(g.dealerHasBlackJack() == true);
	// player lost
	p = Player();
	p.acceptCard(ace);
	p.acceptCard(deuce);
	p.acceptCard(ace);
	dealer = Player();
	dealer.acceptCard(ten);
	dealer.acceptCard(seven);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == false);
	assert(g.playerWon() == false);
	assert(g.playerLost() == true);
	assert(g.playerHasBlackJack() == false);
	assert(g.dealerHasBlackJack() == false);
	// player lost
	p = Player();
	p.acceptCard(ace);
	p.acceptCard(deuce);
	dealer = Player();
	dealer.acceptCard(ten);
	dealer.acceptCard(six);
	dealer.acceptCard(ace);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == false);
	assert(g.playerWon() == false);
	assert(g.playerLost() == true);
	assert(g.playerHasBlackJack() == false);
	assert(g.dealerHasBlackJack() == false);
	// player lost & dealer 21
	p = Player();
	p.acceptCard(ace);
	p.acceptCard(deuce);
	dealer = Player();
	dealer.acceptCard(ten);
	dealer.acceptCard(six);
	dealer.acceptCard(five);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == false);
	assert(g.playerTied() == false);
	assert(g.playerWon() == false);
	assert(g.playerLost() == true);
	assert(g.playerHasBlackJack() == false);
	assert(g.dealerHasBlackJack() == false);
	// player lost & player busted
	p = Player();
	p.acceptCard(ten);
	p.acceptCard(seven);
	p.acceptCard(ace);
	p.acceptCard(four);
	dealer = Player();
	dealer.acceptCard(ten);
	dealer.acceptCard(six);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == true);
	assert(g.playerTied() == false);
	assert(g.playerWon() == false);
	assert(g.playerLost() == true);
	assert(g.playerHasBlackJack() == false);
	assert(g.dealerHasBlackJack() == false);
	// player lost & dealer 21 & player busted
	p = Player();
	p.acceptCard(ten);
	p.acceptCard(six);
	p.acceptCard(six);
	dealer = Player();
	dealer.acceptCard(ten);
	dealer.acceptCard(six);
	dealer.acceptCard(five);
	g = Game(p, dealer);
	g.playerStands();
	g.dealerStands();
	assert(g.dealerBusted() == false);
	assert(g.playerBusted() == true);
	assert(g.playerTied() == false);
	assert(g.playerWon() == false);
	assert(g.playerLost() == true);
	assert(g.playerHasBlackJack() == false);
	assert(g.dealerHasBlackJack() == false);

	cerr << "all tests passed!" << endl;

	return (0);
}

	
//	string action;
//    Game g;
//    g.deal();
//    clearScreen();
//    if (g.playerHasBlackJack() || g.dealerHasBlackJack())
//    {
//        g.playerStands();
//        g.dealerStands();
//    }
//    else
//    {
//        do
//        {
//            g.display( "(h)it (s)tand or (q)uit:" );
//            getline( cin, action );
//            if (action.size() == 0)
//            {
//                g.playerStands();
//            }
//            else
//            {
//                switch (action[0])
//                {
//                    default:   // if bad move, nobody moves
//                        cout << '\a' << endl;  // beep
//                        continue;
//                    case 'Q':
//                    case 'q':
//                        return 0;
//                    case 'h':
//                    case 'H':
//                        g.playerHits();
//                        clearScreen();
//                        break;
//                    case 's':
//                    case 'S':
//                        g.playerStands();
//                        break;
//                }
//            }
//        } while( !g.playerBusted() && !g.playerStood() );
//    
//        clearScreen();
//        g.dealerPlays();
//    }
//    
//    if (g.playerWon())
//    {
//        g.display( "WON!", true );
//    }
//    else if (g.playerLost())
//    {
//        g.display( "LOST!", true );
//    }
//    else
//    {
//        g.display( "TIED!", true );
//    }
//    
// 
//    
//    return 0;
//}
//
//
//
//
/////////////////////////////////////////////////////////////////////////////
////  clearScreen implementations
/////////////////////////////////////////////////////////////////////////////
//
//// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
//// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.
//
//// Note to Xcode users:  clearScreen() will just write a newline instead
//// of clearing the window if you launch your program from within Xcode.
//// That's acceptable.
//
//#ifdef _MSC_VER  //  Microsoft Visual C++
//
//#include <windows.h>
//
//void clearScreen()
//{
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    CONSOLE_SCREEN_BUFFER_INFO csbi;
//    GetConsoleScreenBufferInfo(hConsole, &csbi);
//    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
//    COORD upperLeft = { 0, 0 };
//    DWORD dwCharsWritten;
//    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
//                               &dwCharsWritten);
//    SetConsoleCursorPosition(hConsole, upperLeft);
//}
//
//#else  // not Microsoft Visual C++, so assume UNIX interface
//
//#include <cstring>
//#include <cstdlib>
//
//void clearScreen()  // will just write a newline in an Xcode output window
//{
//    using namespace std;
//    static const char* term = getenv("TERM");
//    if (term == NULL  ||  strcmp(term, "dumb") == 0)
//    {
//        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
//    }
//    else
//    {
//        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
//        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
//    }
//}
//
//#endif
