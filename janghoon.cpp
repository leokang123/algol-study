#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, k;
int minSum = 200001;
void dfs(vector<int>& board, int level, int sum) {
  if (sum > minSum) return; 
  if (sum - k >= 0) {
    minSum = min(minSum, sum);
    return ;
  }
  if (level == n) {
    return ;
  }
  dfs(board, level + 1, sum);
  dfs(board, level+1, sum + board[level]);
}

int main (void) {
  int T; cin >> T;
  for (int test_case = 1 ; test_case <= T ; test_case++) {
    minSum = 200001;
    cin >> n >> k;
    vector<int> board(n);
    for (auto& num : board) cin >> num;
    dfs(board, 0, 0);
    cout << '#' << test_case << ' ' <<  minSum - k << '\n';
  }
}