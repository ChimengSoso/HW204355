/**
 *    author:  ChimengSoso
 *    created: Tue Apr 09 2019 16:54:04
 *    file:    LEC21_01.cpp
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF = 2e9;

int cpt[N][N], p[N];
vector<int> gph[N];

int bfs(int s, int t, int n) {
  fill(p, p+n+1, -1); p[s] = -2;
  queue<pair<int, int>> q; q.push({s, INF});
  
  while (!q.empty()) {
    int cur = q.front().first;
    int flow = q.front().second;
    q.pop();

    for (int nxt: gph[cur]) {
      if (cpt[cur][nxt] == 0 || p[nxt] != -1) continue;
      p[nxt] = cur;
      int new_flow = min(flow, cpt[cur][nxt]);
      if (nxt == t) return new_flow;
      q.push({nxt, new_flow});
    }
  }

  return 0;
}

int main() {
  // freopen("input.txt", "r", stdin);
  int n, s, t, E; scanf("%d%d%d%d", &n, &s, &t, &E);
  for (int i = 0; i < E; ++i) {
    int u, v, c; scanf("%d%d%d", &u, &v, &c);
    tie(cpt[u][v], cpt[v][u]) = make_tuple(cpt[u][v]+c, cpt[v][u]+c);
    gph[v].push_back(u); gph[u].push_back(v);
  }

  int mxf = 0, new_flow;
  while (new_flow = bfs(s, t, n)) {
    mxf += new_flow;
    int cur = t;
    while (cur != s) {
      int prev = p[cur];
      cpt[prev][cur] -= new_flow;
      cpt[cur][prev] += new_flow;
      cur = prev;
    }
  }

  printf("%d\n", mxf);
  return 0;
}