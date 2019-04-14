/**
 *    author:  ChimengSoso
 *    created: Wed Mar 20 2019 23:51:27
 *    file:    LEC18_02.cpp
**/
#include <bits/stdc++.h>
using namespace std;

int n;
bool gph[30][30];
bool vst[30];

void dfs(int u) {
  if (vst[u]) return;
  vst[u] = true;
  for (int v = 0; v < n; ++v) {
    if (gph[u][v] && !vst[v])
      dfs(v);
  }
}

int main() {
  // freopen("input.txt", "r", stdin);
  char mxNode; scanf("%c", &mxNode);
  n = mxNode - 'A' + 1;

  string E;
  while (cin >> E) {
    int a = E[0]-'A';
    int b = E[1]-'A';
    gph[a][b] = gph[b][a] = true;
  }

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (!vst[i]) {
      cnt++;
      dfs(i);
    }
  }
  printf("%d\n", cnt);
  return 0;
}