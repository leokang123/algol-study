#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;
int vis[101];
int main (void) {

  for (int test_case = 1; test_case <= 10 ; test_case++) {

    int n, st; cin >> n >> st;
    unordered_map<int, vector<int>> board;

    for (int i = 0 ; i < n/2 ; i++) {
      int from, to; cin >> from >> to;
      board[from].push_back(to);
    }

    // 현재노드, 현재 순서
    queue<pair<int, int>> que;

    que.push({st, 0});
    vis[st] = 1;

    int curDis = 0;
    int curMax = st;

    while(!que.empty()) {
      auto [cur, dis] = que.front(); que.pop();

      if (dis != curDis) {
        curDis = dis;
        curMax = cur;
      } else if (cur > curMax) {
        curMax = cur;
      }

      auto candidates = board[cur];
      for (auto candidate : candidates) {
        if (vis[candidate]) continue;
        que.push({candidate, dis+1});
        vis[candidate] = 1;
      }
      
    }
    
    cout << '#' << test_case << ' ' << curMax << '\n';
  }

  return 0;

}