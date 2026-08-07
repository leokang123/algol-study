#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string maxStr = "";

// 근본적으로 틀린 이유 level을 인덱스로 삼고 for 문 돌면서 순서대로 0번인덱스 1번인덱스 숫자가 바뀌게 설계했는데 
// 이러면 구조적으로 무조건 문제가 생김, 반드시 앞에 숫자들을 바꿔야하는 문제, 차리리 이중 포문을 도는게 나을수도 있음 
// 그냥 최대 자릿수가 6자리니까 이중포문돌아보자 

// 45분 
void dfs(string str, int level, int p) {
  int n = str.size();
  if (level == n || p == 0) {
    if (p == 0) maxStr = max(str, maxStr);
    return;
  }
  // cout << str << '\n';
  for (int i = 0 ; i < n ; i++) {
    if (i == level) continue;
    dfs(str, level+1, p);
    swap(str[level], str[i]);
    dfs(str, level+1, p-1);
    swap(str[level], str[i]);
  }
}

int main (void) {
  int T; cin >> T;
  for (int test_case = 0 ; test_case < T ; test_case++) {
    maxStr = "";
    string str; cin >> str;
    int p ; cin >> p;
    while (p >= str.size()) p -= 2;
    dfs(str, 0, p);

    cout << '#' << test_case+1 << ' ' <<  maxStr << '\n';
  }

  return 0;
}