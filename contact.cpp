#include <iostream>
#include <algorithm>
using namespace std;


int main (void) {

  pair<int,int> p1 = {1,1};
  pair<int,int> p2 = {1, 1};

  bool isTrue = p1 == p2;
  cout << isTrue << '\n';

  return 0;
}