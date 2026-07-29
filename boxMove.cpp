#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (void) {
  int n; cin >> n;
  vector<int> board(100);
  int maxVal = 0;
  int minVal = 101;
  for (int i = 0 ; i < 100 ; i++) {
    cin >> board[i];
    minVal = min(minVal, board[i]);
    maxVal = max(maxVal, board[i]);
  }

  // 잘은 모르겠지만 이분탐색이 가장 편리해보임 
  // 범위가 1~100 이니까 (0, 101) 에서 이분탐색을 하고 
  // mid 기준으로 값을 뺐을때 나오는 양수 값이 덤프 횟수라 판단
  // 아마 전체 덤프에 딱 맞게 떨어지지 않을거기 때문에 이에 대한 판단만 잘하면 될듯 
  // 그떄 구한 mid 값 기준 기존 최댓값과 최솟값을 ?
  int low = 0;
  int high = 101;
  while (low + 1 < high) {
    int mid = (low + high) / 2;
    int sum = 0;
    for (int b : board){
      int t = b - mid;
      if (t > 0) sum += t;
    }
    // 덤프보다 더 많이 옮겼을때, low를 높혀야함 
    if (sum > n) {
      low = mid;
    } else {
      high = mid;
    }
  }

  int high1 = 101;
  int low1 = 0;
  while (low1 + 1 < high1) {
    int mid = (low1 + high1) / 2;
    int sum = 0;
    for (int b : board) {
      int t = mid - b;
      if (t > 0) sum += t;
    }
    // 더 많이 옮긴 경우 -> 줄여야함 
    if (sum > n) {
      high1 = mid;
    } else {
      low1= mid;
    }
  }
  cout << high - low1 << '\n';
  return 0;
}