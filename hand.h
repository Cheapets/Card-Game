#ifndef HAND_H
#define HAND_H
#include <utility>
#include "card.h"
#include "deck.h"
#include "poker.h"
#define MAX_CARDS 5

enum Hand { single, singlePair, TwoPair, threeKind, straight, Flush, fullHouse, fourKind, straightFlush, royalFlush };

class PokerHand{
 private:
  Cards *pokerHand;
  bool showCards;

 public:
  PokerHand(); 
  void ShowCards(bool showCards_);
  void showHand();
  void printHand();
  void draw(DeckOfCards& deck, int amount = 0);
  
  bool CheckFourKind();
  bool CheckStraight();
  bool CheckFlush(); 
  bool CheckFullHouse();
  bool CheckStraightFlush();
  bool CheckRoyalFlush();
  bool CheckPair();
  bool CheckTwoPair();
  bool CheckThreeKind();

  Hand getHand();
  Cards& operator[](int index);
  void sortDeck(int amount = 5);
 
  ~PokerHand();
};

#endif
