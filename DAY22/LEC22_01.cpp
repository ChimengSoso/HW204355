/**
 *    author:  ChimengSoso
 *    created: Wed Apr 10 2019 15:21:23
 *    file:    LEC22_01.cpp
**/
#include <bits/stdc++.h>
using namespace std;

const int src = 38;
const int snk = 39;
const int INF = 2e9;

vector<int> gph[40];
int p[40];
int rgph[40][40]; // alphabet + number
int bfs() {
  fill(p, p+40, -1); p[src] = -2;
  queue<pair<int, int>> q; q.push({src, INF});
  while (!q.empty()) {
    int u = q.front().first;
    int f = q.front().second;
    q.pop();
    for (int v : gph[u]) {
      if (p[v] != -1 || rgph[u][v] == 0) continue;
      p[v] = u;
      int nf = min(f, rgph[u][v]);
      if (v == snk) return nf;
      q.push({v, nf});
    }
  }
  return 0;
}

void addEdge(int u, int v) {
  gph[u].push_back(v);
  gph[v].push_back(u);
}

int main() {
  // freopen("input.txt", "r", stdin);
  int t; scanf("%d", &t);
  int rqr = 0;
  for (int I = 0; I < t; ++I) {
    char c; int n; char s[105];
    scanf(" %c %d %s", &c, &n, s);
    int u = c-'A';
    rqr += rgph[src][u] = n;
    addEdge(src, u);
    for (int i = 0; s[i]; ++i) {
      if (!isalnum(s[i])) break;
      int v = 26+s[i]-'0';
      rgph[u][v] = rgph[v][snk] = 1;
    }
  }
  
  for (int u = 0; u < 40; ++u) {
    for (int v = u+1; v < 40; ++v) {
      if (rgph[u][v])
        addEdge(u, v);
    }
  }

  int nf, mxf = 0;
  while (nf = bfs()) {
    mxf += nf;
    int u = snk;
    while (u != src) {
      int v = p[u];
      rgph[v][u] -= nf;
      rgph[u][v] += nf;
      u = v;
    }
  }

  if (mxf != rqr)
    return printf("!"), 0;
  
  char rlt[15] = {};
  for (int i = 0; i < 26; ++i) {
    if (gph[i].size() == 0) continue;
    for (int j = 26; j < 26+10; ++j) {
      int idx = j-26;
      if(rlt[idx] == 0)
        rlt[idx] = '_';
      if (rgph[j][i] && rlt[idx] == '_')
        rlt[idx] = (char)i+'A';
    }
  }
  rlt[10] = '\0';

  printf("%s\n", rlt);
  return 0;
}