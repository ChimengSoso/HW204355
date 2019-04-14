/**
 *    author:  ChimengSoso
 *    created: Wed Apr 10 2019 14:10:16
 *    file:    LEC22_02.cpp
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int INF = 2e9;

int cpt[N][N], p[N];
vector<int> gph[N];

int bfs(int n) {
  fill(p, p+n+1, -1); p[1] = -2;
  queue<pair<int, int>> q; q.push({1, INF});
  while (!q.empty()) {
    int cur = q.front().first;
    int flow = q.front().second;
    q.pop();
    for (int nxt : gph[cur]) {
      if (p[nxt] != -1 || cpt[cur][nxt] == 0) continue;

      p[nxt] = cur;
      int new_flow = min(flow, cpt[cur][nxt]);
      
      if (nxt == 2) return new_flow;
      q.push({nxt, new_flow});
    }
  }
  return 0;
}

int main() {
  // freopen("input.txt", "r", stdin);
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v, c; scanf("%d%d%d", &u, &v, &c);
    cpt[u][v] = cpt[v][u] = c;
    gph[u].push_back(v); gph[v].push_back(u);
  }

  int new_flow, mxf = 0;
  while (new_flow = bfs(n)) {
    int cur = 2;
    mxf += new_flow;
    while (cur != 1) {
      int prev = p[cur];
      cpt[prev][cur] -= new_flow;
      cpt[cur][prev] += new_flow;
      cur = prev;
    }
  }
  
  fill(p, p+n+1, 0);
  queue<int> q; q.push(1);
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    p[cur] = 1;
    for (int nxt : gph[cur]) {
      if (cpt[cur][nxt] && p[nxt] == 0)
        q.push(nxt);
    }
  }

  for (int u = 1; u <= n; ++u) {
    sort(gph[u].begin(), gph[u].end());
    if (!p[u]) continue;
    for (int v : gph[u]) {
      if (p[v]) continue;
      printf("%d %d\n", u, v);
    }
  }
  return 0;
}