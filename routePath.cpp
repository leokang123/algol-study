#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int board[101][2];
int visit[101];

int isRoute = 0;
void dfs(int curNode) {
  if (curNode == 99) {
    isRoute = 1;
    return;
  }

  for (int i = 0 ; i < 2; i++) {
    int nn = board[curNode][i];
    if (!nn) continue;
    dfs(nn);
  }


}
// 25분 
int main (void) {
  int T; // cin >> T;
  T = 10;
  vector<string> result;
  for (int test_case = 1 ; test_case <= T ; test_case++) {
    for (int r = 0 ; r < 101 ; r++) fill(board[r], board[r] + 2, 0);
    isRoute = 0;
    int t ; cin >> t;
    int e; cin >> e;
    for (int i = 0 ; i < e ; i++) {
      int from, to; cin >> from >> to;
      if (!board[from][0]) board[from][0] = to;
      else board[from][1] = to;
    }

    dfs(0);
    string ptr = "# " + to_string(t) + ' ' +  to_string(isRoute);
    result.push_back(ptr);

  }

  for (auto str : result) cout << str << '\n';
  return 0;
}