#include <iostream>
#include <vector>

using namespace std;

int n;

// n/2 만 뽑아도 됨 

int vis[17];
int score = 20001;

void dfs(vector<vector<int>>& board, int level, int prev) {
  if (level == n/2) {
    int sum1 = 0;
    for (int i = 0 ; i < n ; i++) {
      if (!vis[i]) continue;
      for (int j = i+1 ; j< n ; j++) {
        if (!vis[j]) continue;
        cout << i << ' ' << j << '\n' ;
        sum1 += board[i][j] + board[j][i];
      }
    }
    int sum2 = 0;
    for (int i = 0 ; i < n ; i++) {
      if (vis[i]) continue;
      for (int j = i+1 ; j< n ; j++) {
        if (vis[j]) continue;
        sum2 += board[i][j] + board[j][i];
      }
    }

    cout << '\n';

    if (sum1 >= sum2) score = min(score, sum1 - sum2);
    else score = min(score, sum2 - sum1);
    return;
  }

  for (int i = prev ; i < n ; i++) {
    if(vis[i]) continue;
    vis[i] = 1;
    dfs(board, level+1, i+1);
    vis[i] = 0;
  }


}

int main (void) {
  int T; cin >> T;

  for (int test_case = 1 ; test_case <= T; test_case++) {
    score = 20001;
    fill(vis,vis+17,0);
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < n ; j++) {
        cin >> board[i][j];
      }
    }

    dfs(board, 0, 0);

    cout << '#' << test_case << ' ' << score << '\n';
  }

  return 0;
}