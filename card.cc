#include "card.h"
#include "deck.h"
#include <cstdlib>
using namespace std;

string Cards::faces[13] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
string Cards::suits[4] = {"Spade", "Club", "Diamond", "Heart"};

Cards::Cards(int face_, int suit_): face(face_ % 13), suit(suit_ % 4) {}
Cards::Cards() {}

string Cards::String()
{
  return faces[face] + " of " + suits[suit];
}

int Cards::getFace()
{ 
  return face; 
}

int Cards::getSuit() 
{ 
  return suit; 
}

int Cards::Number()
{
  int temp = face * 10 + suit;
  return temp;
}


Cards DeckOfCards::dealCard() 
{
  if(!moreCards())
    exit(1);
  Cards card = Cards( currentCard / 10, currentCard % 4);
  deck.pop_back();
  currentCard = deck.back().Number();
  return card;
}





