#ifndef POKER_H
#define POKER_H
#include "card.h"
#include "deck.h"
#include "hand.h"
#define MAX_CARDS 5

class Poker {
private:
  DeckOfCards deck;
  PokerHand player;
  PokerHand dealer;

public:
  Poker();  
  void gameOver();
  void print();
  void testfunction1(), testfunction2(), testfunction3();
  // allow user to swap the cards part 5
  void smartSwap(), userSwap();
  void start();
};

#endif
