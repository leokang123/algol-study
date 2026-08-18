#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxK;
int n;
int score;
int vis[21];

void dfs(vector<vector<int>>& info, int level, int curS, int curK) {
  score = max(score, curS);

  for (int i = level ; i < n ; i++) {
    if (vis[i]) continue;
    int tmpS = info[i][0];
    int tmpK = info[i][1];
    if (curK + tmpK > maxK) continue;
    vis[i] = 1;
    dfs(info, i+1, curS + tmpS, curK + tmpK);
    vis[i] = 0;
  }

}

int main (void) {
  int T; cin >> T;
  for (int test_case = 1 ; test_case <= T ; test_case++) {
      cin >> n >> maxK;
      score = 0;
      fill(vis, vis+21, 0);

      vector<vector<int>> info(n, vector<int>(2));
      for (int i = 0 ; i < n ; i++) {
        int a, b;
        cin >> a >> b;
        info[i][0] = a;
        info[i][1] = b;
      }

      dfs(info, 0, 0, 0);

      cout << '#' << test_case << ' ' << score << '\n';


  }
}