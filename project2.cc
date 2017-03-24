#include "poker.h"
#include "deck.h"
#include "hand.h"
#include <iostream>

int main()
{
  Poker a;
  //First test
  cout << "//======== TEST 1 =======//" << endl;
  a.testfunction1();
  cout<< endl;
  //Second test
  cout << "//======== TEST 2 =======//" << endl;
  a.testfunction2();
  cout << endl;
  //Third test
  cout << "//======== TEST 3 =======//" << endl;
  a.testfunction3();
  a.start();
  return 0;
}


