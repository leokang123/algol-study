#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int isRoute = 0;

// 양방향이 없다는 말이없어서 vis 체크 필요할듯 
int vis[51];
void dfs(vector<vector<int>>& board, int cur, int ed) {
  if (isRoute) return;
  if (cur == ed) {
    isRoute = 1;
    return ;
  }

  for (auto candidate : board[cur]) {
    if (vis[candidate]) continue;
    vis[candidate] = 1;
    dfs(board, candidate, ed);
    vis[candidate] = 0;
  }

  auto candidates = board[cur];

}

int main (void) {
  int T; cin >> T;
  for (int test_case = 1; test_case <= T ; test_case++) {
    isRoute = 0;
    fill(vis, vis + 51, 0);
    int v, e; cin >> v >> e;

    // 따로 이진트리라는 말은 없음
    vector<vector<int>> board(v+1);
    for (int i = 0 ; i < e ; i++) {
      int from, to; cin >> from >> to;
      board[from].push_back(to);
    }

    int st, ed; cin >> st >> ed;
    vis[st] = 1;
    dfs(board, st, ed);
    cout << '#' << test_case << ' ' << isRoute << '\n';

  }
  return 0;
}