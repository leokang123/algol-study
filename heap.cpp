#include <iostream>
#include <vector>
using namespace std;

void heapify2(vector<int>& board, int cur, int idx) {
    int left = cur * 2;
    int right = cur *2 +1;
    if (left >= idx) return;

    int bigIdx = left;
    if (right < idx && board[right] > board[left]) bigIdx = right;
    if (board[cur] >= board[bigIdx]) return;

    int tmp = board[bigIdx];
    board[bigIdx] = board[cur];
    board[cur] = tmp;
    heapify2(board, bigIdx, idx);    
}


void heapify(int idx, vector<int>& heap) {
  // 7 
  // 부모는 3 
  if (idx == 1) return ;
  int parIdx = idx/2;
  if (heap[parIdx] >= heap[idx]) return ;

  int tmp = heap[parIdx];
  heap[parIdx] = heap[idx];
  heap[idx] = tmp;
  heapify(parIdx, heap);
  // 부모와 비교 
}

int main (void) {
  int n ; cin >> n;
  int idx = 1;
  vector<int> ans;
  vector<int> heap(100001);
  for (int i = 0 ; i < n ; i++) {
    int cmd; cin >> cmd;
    if (cmd == 1) {
      cin >> heap[idx];
      heapify(idx, heap);
      idx++;
    } else if (cmd == 2)  {
      if (idx == 1) ans.push_back(-1);
      else {
        ans.push_back(heap[1]);
        heap[1] = heap[--idx];
        heapify2(heap, 1, idx);
      }
    }
  }
  for (auto a : ans) {
    cout << a << ' ';
  }
  cout << '\n';
  return 0;
}