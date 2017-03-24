#include "deck.h"
#include <cstdlib>

using namespace std;

DeckOfCards::DeckOfCards()
{
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 13; j++)
      deck.push_back(Cards(j, i));
  currentCard = deck.back().Number();
}

bool DeckOfCards::moreCards()
{
  if (deck.size() == 0)
    return false;
  else
    return true;
}

int DeckOfCards::getCurrent() 
{
  currentCard = deck.back().Number();
  return currentCard;
}

void DeckOfCards::shuffle()
{
  srand(time(NULL));
 
  for (int i = 0; i < deck.size(); i++)
    swap(deck[i], deck[rand() % 52]);
  currentCard = deck.back().Number();
}

void DeckOfCards::print()
{
  for (int i = 0; i < deck.size(); i++)
    cout << i + 1 << ". " << deck[i].String() << endl;
}


