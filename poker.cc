#include "poker.h"
#include "deck.h"
#include "card.h"
#include "hand.h"
#include <cstdlib>

Poker::Poker()
{
  //Shuffles deck
  deck.shuffle();
  //Displays AI(S) hand
  dealer.ShowCards(false);
}
void Poker::testfunction1()
{
  Cards zero(2, 0);
  Cards one(3, 0);
  Cards two(9, 0);
  Cards three(11, 0);
  Cards four(5, 0);
  Cards five(8, 0);
 
  player[0], dealer[0] = zero;
  player[1], dealer[1] = one;
  player[2], dealer[2] = two;
  player[3], dealer[3] = three;
  player[4], dealer[4] = four;
  gameOver();
}

void Poker::testfunction2()
{
  for(int k = 0; k < 5; k++)
  {
    player[k] = deck.dealCard();
    dealer[k] = deck.dealCard();
  }
  gameOver();
}

void Poker::testfunction3()
{
  for(int i = 0; i < 5; i++)
  {
    player[i] = deck.dealCard();
    dealer[i] = deck.dealCard();
  }
  gameOver();
}

void Poker::start()
{
  for(int i = 0; i < 5; i++)
  {
    player[i] = deck.dealCard();
    dealer[i] = deck.dealCard();
  }

  userSwap();
}

void Poker::print()
{
  cout << "//======= PLAYERS HAND =======//" << endl;
  player.showHand();

  cout << "//====== COMPUTERS HAND ======//" << endl;
  dealer.showHand();
}

void Poker::userSwap()
{
  int *index;
  int amount;

  cout << "*CURRENT HAND: ";
  player.printHand();  

  cout << "*REPLACE YOUR HAND(HOW MANY): ";
  cin >> amount;
  index = new int[amount];


  cout << "*WHICH CARDS: " << endl;
  cout << "OK, REMOVING " << amount << endl;  
  player.sortDeck();  
  delete index;
}

void Poker::gameOver()
{
  //Displays hands 
  dealer.ShowCards(true);
  print();

  //Displays Player hand
  cout << "*PLAYER(s) HAND: ";
  player.printHand();

  //Displays AI(S) hand
  cout <<"*AI(S) HAND: ";
  dealer.printHand();
	
  //Compares hands from AI to Player
  if(player.getHand() > dealer.getHand())
    cout << "PLAYER 1 WINS!" << endl;

  //Compares hands from Player to AI
  else if(player.getHand() < dealer.getHand())
    cout << "AI WINS!" << endl;
  else {
   
    cout << "DRAWING HAND, ";
    for(int i = MAX_CARDS - 1; i >= 0; i--)
    {
      //Comparing is Player's card is higher
      if(player[i].getFace() > dealer[i].getFace())
      {
        cout << "PLAYER HAS THE HIGHER CARD" << endl;
        break;
      }
      //Comparing if AI's hand is higher
      else if(player[i].getFace() < dealer[i].getFace())
      {
        cout << "AI HAS THE HIGHER CARD" << endl;
        break;
      }
    }
  }
  cout << endl;
}



