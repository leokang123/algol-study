#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int res = 0;
int count = 0;


int dfs(vector<vector<int>>& board, vector<int>& mark, int cur, int t1, int t2) {
  auto childs = board[cur];
  mark[cur] = 1;
  int cnt = 0;
  if (cur == t1 || cur == t2) cnt = 1;

  for (auto child : childs) {
    cnt += dfs(board, mark, child, t1, t2);
    mark[cur] += mark[child];
  }
  if (cnt == 2 && res == 0) {
    res = cur;
  } 

  return cnt;
}



int main (void) {
  int v, e; cin >> v >> e;
  int a, b; cin >> a >> b;

  // [v+1][2] 구조 
  vector<vector<int>> board(v+1);
  vector<int> mark(v+1, 0);
  for (int i = 0 ; i < e ; i++) {
    int v1, v2; cin >> v1 >> v2;
    board[v1].push_back(v2);
  }

  dfs(board,mark, 1, a, b);

  cout << res << ' ' << mark[res] << '\n';


  return 0;
}
