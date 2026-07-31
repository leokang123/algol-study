#include <iostream>
#include <vector>

using namespace std;
int res;
int n, k;
void dfs(int level, int cnt, int sum) {
  if (sum > k) return;
  if (level == 13) {
    if (sum == k && cnt == n) res++;
    return;
  }
  dfs(level+1, cnt+1, sum + level);
  dfs(level+1, cnt, sum);
}

int main (void) {
  cin >> n;
  cin >> k;
  dfs(1, 0, 0);
  cout << res << '\n';

  return 0; 

}