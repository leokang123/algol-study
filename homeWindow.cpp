#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (void) {
  // 5개 짜리 슬라이딩 윈도우에서 가장 큰값과 그다음 큰값을 갱신해서 한칸 옮길떄마다 그 차이를 누적합하면 될것 같다 
  int n; cin >> n;
  vector<int> board(n);
  for (int i = 0 ; i < n ; i++) {
    cin >> board[i];
  }
  int sum = 0;
  int idx = 2;
  while (idx < n-2) {
    int base = board[idx];
    int maxVal = 0;
    for (int j = idx-2; j < idx+3; j++) {
      if (board[j] == base) continue;
      if (maxVal < board[j]) maxVal = board[j];
    }
    if (maxVal >= base) {
      idx++;
      continue;
    };
    sum += base - maxVal;
    idx += 2;
  }

  cout << sum << '\n';
  return 0;
}