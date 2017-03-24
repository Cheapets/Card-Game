#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include <string>
#include "card.h"

class DeckOfCards {
 private:
  //Vector of "Cards" for the "Deck"
  vector<Cards> deck;
  //Variable for "currentCard"
  int currentCard;

 public:

  DeckOfCards();
  Cards dealCard();
  int getCurrent();
  bool moreCards();
  void printDeck();
  void shuffle();
  void print();
};

#endif
