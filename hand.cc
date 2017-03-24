#include "poker.h"
#include "deck.h"
#include "card.h"
#include <cstdlib>

PokerHand::PokerHand() 
{
  pokerHand = new Cards[MAX_CARDS];
  showCards = true;
}

void PokerHand::draw(DeckOfCards& deck, int amount)
{
  if(amount > MAX_CARDS)
    return;

  for(int i = 0; i < amount; i++)
    pokerHand[i] = deck.dealCard();
}

void PokerHand::showHand()
{
  int j = 1;
  if(showCards == false)
    cout << "Face down cards" << endl;
  else {
    for(int i = 0; i < MAX_CARDS; i++)
      cout << j++ << ". " << pokerHand[i].String() << endl;
  }
  cout << endl;
}

void PokerHand::ShowCards(bool showCards_) 
{
  showCards = showCards_;
}

void PokerHand::sortDeck(int amount)
{
  if(amount > MAX_CARDS)
    return;
  for(int i = 0; i < amount; i++)
    for(int j = i+1; j < amount; j++)
      if(pokerHand[i].getFace() > pokerHand[j].getFace())
        swap(pokerHand[j], pokerHand[i]);
}

Cards& PokerHand::operator[](int index)
{
  if(index > 5)
    exit(1);
  return pokerHand[index];
}

PokerHand::~PokerHand()
{
  delete pokerHand;
}

bool PokerHand::CheckPair()
{
  for(int i = 0; i < MAX_CARDS - 1; i++)
    if(pokerHand[i].getFace() == pokerHand[i+1].getFace())
      {
	swap(pokerHand[i], pokerHand[4]);
	swap(pokerHand[i + 1], pokerHand[3]);
	sortDeck(3);
	return true;
      }
  return false;
}

bool PokerHand::CheckTwoPair()
{
  int index[2] = {0};
  int count = 0;
  for(int i = 0; i < MAX_CARDS - 1; i++)
    if(pokerHand[i].getFace() == pokerHand[i+1].getFace())
      {
	index[count] = i; 
	count++;
      }
  if(count == 2)
    {
      if(pokerHand[index[0]].getFace() > pokerHand[index[1]].getFace())
	{
	  for(int i = 0; i < 2; i++)
	    {
	      swap(pokerHand[index[0] + i], pokerHand[4 - i]);
	      swap(pokerHand[index[1] + i], pokerHand[2 - i]);
	    }
	}
      else {
	for(int i = 0; i < 2; i++)
	  {
	    swap(pokerHand[index[0] + i], pokerHand[4 - i]);
	    swap(pokerHand[index[1] + i], pokerHand[2 - i]);
	  }
      
      }
      return true;
    }
  return false;
}

bool PokerHand::CheckThreeKind()
{
  for(int i = 0; i < MAX_CARDS - 2; i++)
    if(pokerHand[i].getFace() == pokerHand[i+2].getFace())
      {
	for(int j = i; j < 2; j++)
	  swap(pokerHand[j], pokerHand[4 - j]);
	sortDeck(2);
	return true;
      }
  return false;
}

bool PokerHand::CheckFourKind()
{
  for(int i = 0; i < MAX_CARDS - 3; i++)
    if(pokerHand[i].getFace() == pokerHand[i+3].getFace())
      {
	if(i == 0)
	  swap(pokerHand[0], pokerHand[4]);
	return true;
      }
  return false;
}

bool PokerHand::CheckStraight()
{
  if(!CheckPair() && pokerHand[0].getFace() == pokerHand[4].getFace() - 4)
    return true;
  return false;
}

bool PokerHand::CheckFlush()
{
  for(int i = 0; i < MAX_CARDS - 1; i++)
    if(pokerHand[i].getSuit() != pokerHand[i+1].getSuit())
      return false;
  return true;
}

bool PokerHand::CheckFullHouse()
{
  if(CheckTwoPair() && CheckThreeKind())
    return true;
  return false;
}

bool PokerHand::CheckStraightFlush()
{
  if(CheckFlush() && CheckStraight())
    return true;
  return false;
}

bool PokerHand::CheckRoyalFlush()
{
  if(CheckStraightFlush() && pokerHand[4].getFace() == 12)
    return true;
  return false;
}

Hand PokerHand::getHand()
{
  sortDeck();

  if(CheckRoyalFlush())
    return royalFlush;

  else if(CheckStraightFlush())
    return straightFlush;

  else if(CheckFourKind())
    return fourKind;

  else if(CheckFullHouse())
    return fullHouse;

  else if(CheckFlush())
    return Flush;

  else if(CheckStraight())
    return straight;

  else if(CheckThreeKind())
    return threeKind;

  else if(CheckTwoPair())
    return TwoPair;

  else if(CheckPair())
    return singlePair;

  else
    return single;
}

void PokerHand::printHand()
{
  switch(getHand())
    {
    case royalFlush: 
      cout << "Royal Flush";
      break;

    case straightFlush:
      cout << "Straight Flush";
      break;

    case fourKind:
      cout << "Four of a Kind";
      break;

    case fullHouse:
      cout << "Full House";
      break;

    case Flush:
      cout << "Flush";
      break;

    case straight:
      cout << "Straight";
      break;

    case threeKind:
      cout << "Three of a Kind";
      break;

    case TwoPair:
      cout << "Two pair";
      break;

    case singlePair:
      cout << "One pair";
      break;

    case single:
      cout << "High card";
      break;

    default:
      cout << "No connection in the cards";
      break;
    }
  cout << endl;
}
