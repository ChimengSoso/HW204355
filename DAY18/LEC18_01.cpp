/**
 *    author:  ChimengSoso
 *    created: Mon Mar 18 2019 22:26:02
 *    file:    LEC18_01.cpp
**/
#include <bits/stdc++.h>
using namespace std;

vector<string> Map;

bool vst[105][105];

int ans[105], cpn[105][105];

int n, m;

int dx[] = {1, -1, 0,  0,  1, 1, -1, -1};
int dy[] = {0,  0, 1, -1, -1, 1,  1, -1};

void dfs(int r, int c, int idx) {
  if (r < 0 || r >= n || c < 0 || c >= m) return;
  if (vst[r][c] || Map[r][c] == 'L') return;
  vst[r][c] = 1;
  ans[idx]++;
  cpn[r][c] = idx;
  for (int k = 0; k < 8; ++k) {
    int x = r + dx[k];
    int y = c + dy[k];
    dfs(x, y, idx);
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  
  string str;
  while (getline(cin, str)) {
    if (str[0] != 'L' && str[0] != 'W')
      break; 
    Map.push_back(str);
  }
  istringstream iss(str);

  n = Map.size();
  m = Map[0].size()-1;
  
  int idx_cpn = 1, r, c;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (Map[i][j] == 'L' || vst[i][j]) continue;
      dfs(i, j, idx_cpn);
      idx_cpn += 1;
    }
  }

  iss >> r >> c;
  printf("%d\n", ans[cpn[r-1][c-1]]);
  
  while (cin >> r >> c) {
    printf("%d\n", ans[cpn[r-1][c-1]]);
  }
  return 0;
}