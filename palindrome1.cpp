#include <iostream>
#include <vector>
#include <string> 

using namespace std;

// 25분 
int main (void) {
  int n; cin >> n;
  vector<vector<char>> board(8, vector<char>(8));

  for (int i = 0 ; i < 8 ; i++) {
    string str ; cin >> str; 
    for (int j = 0 ; j < 8 ; j++) {
      board[i][j] = str[j];
    }
  }

  // 가로 포문 한번 세로 포문 한번 돌릴 생각 
  // 그리고 각각의 포문은 투포인터 방식으로 진행할생각 
  // 아마 n이 짝수인 경우 홀수인경우를 나눠서 풀지 않을까 싶음 
  // n 은 아마 1이상?
  int res = 0;
  for (int i = 0 ; i < 8 ; i++) {
    for (int j = 0 ; j <= 8-n ; j++) {
      int cnt = 0;
      int left = j;
      int right = j+n-1;
      while (left < right) {
        if (board[i][left] == board[i][right]) cnt += 2;
        right--;
        left++;
      }
      if (n % 2 == 1 && left == right) cnt++;
      if (cnt == n) res++;
    }
    
  }

  for (int i = 0 ; i < 8 ; i++) {
    for (int j = 0 ; j <= 8-n ; j++) {
      int cnt = 0;
      int left = j;
      int right = j+n-1;
      while (left < right) {
        if (board[left][i] == board[right][i]) cnt += 2;
        right--;
        left++;
      }
      if (n % 2 == 1 && left == right) cnt++;
      if (cnt == n) res++;
    }
    
  }

  cout << res << '\n';

  return 0;
}