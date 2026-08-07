#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main (void) {
  int t; cin >> t;
  queue<int> q;
  for (int i = 0 ; i < 8 ; i++) {
    int a ; cin >> a;
    q.push(a);
  }
  int base = 1;
  while(true) {
    int top = q.front(); q.pop();
    int num = (top - base <= 0)? 0 : top - base;
    q.push(num);
    if (num == 0) break;
    base = base % 5 + 1;
  }

  cout << '#' << t << ' ';
  while(!q.empty()) {
    cout << q.front() << ' ' ;
    q.pop(); 
  }
  return 0;
}