  #include <iostream>
  #include <vector>
  #include <string>
  #include <algorithm>
  #include <queue> 

  using namespace std;

  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  int main (void) {
    int T; cin >> T;
    for (int test_case = 1 ; test_case <= T; test_case++) {
      int n, m; cin >> n >> m;

      vector<vector<char>> board(n, vector<char>(m));
      vector<vector<vector<int>>> dis(2, vector(n, vector<int>(m, 0)));

      queue<pair<int, int>> suyun, evil;

      for (int i = 0 ; i < n ; i++){
        string tmp; cin >> tmp;
        for (int j = 0 ; j < m ; j++) {
          board[i][j] = tmp[j];
          if (tmp[j] == 'S') {
            suyun.push({i,j});
            dis[0][i][j] = 1;
          }
          if (tmp[j] == '*'){
            evil.push({i,j});
            dis[1][i][j] = 1;
          }
        }
      }

      int route = 0;
      while(!evil.empty()) {
        auto [cy, cx] = evil.front(); evil.pop();
        
        for (int i = 0 ; i < 4; i++) {
          int ny = cy + dy[i];
          int nx = cx + dx[i];
          if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
          if (board[ny][nx] != '.' || dis[1][ny][nx] != 0) continue;
          evil.push({ny,nx});
          dis[1][ny][nx] = dis[1][cy][cx] + 1;
        }
      }

      while(!suyun.empty()) {
        auto [cy, cx] = suyun.front(); suyun.pop();
        if (route != 0) continue; 
        for (int i = 0 ; i < 4; i++) {
          int ny = cy + dy[i];
          int nx = cx + dx[i];
          if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
          if (dis[1][ny][nx] != 0 && dis[0][cy][cx] + 1 >= dis[1][ny][nx]) continue;
          if (board[ny][nx] == 'D') {
            route = dis[0][cy][cx];
            continue;
          }
          if (board[ny][nx] != '.' || dis[0][ny][nx] != 0) continue;
          suyun.push({ny,nx});
          dis[0][ny][nx] = dis[0][cy][cx] + 1;
        }
      }

      if (route != 0) cout << '#' << test_case << ' ' << route << '\n';
      else cout << '#' << test_case << ' ' << "GAME OVER" << '\n';
    }

    return 0;
  }