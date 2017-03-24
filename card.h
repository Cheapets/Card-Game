#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Cards {
private:
  int face;
  int suit;
  static string faces[13];
  static string suits[4];

public:
  Cards(int face_, int suit_);
  Cards();
  string String();
  int Number(); 
  int getFace();
  int getSuit();
};

#endif
