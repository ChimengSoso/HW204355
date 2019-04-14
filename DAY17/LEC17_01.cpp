/**
 *    author:  ChimengSoso
 *    created: Mon Mar 11 2019 23:7:26
 *    file:    LEC17_01.cpp
**/
#include <bits/stdc++.h>
using namespace std;

bool g[105][105], vst[105][105], mrk[105];
int n;

void dfs(int start, int u) {
  if (vst[start][u]) return;
  vst[start][u] = 1;

  for (int v = 1; v <= n; ++v) {
    if (g[u][v]) 
      dfs(start, v);
  }
}

bool reach(int u, int v, int ext) {
  if (mrk[u]) return false;
  if (u == ext || v == ext) return false;
  if (u == v) return true;
  mrk[u] = 1;
  for (int k = 1; k <= n; ++k) {
    if (k == ext || !g[u][k]) continue;
    bool sol = reach(k, v, ext);
    if (sol) 
      return true;
  }
  return false;
}

int main() {
  freopen("input.txt", "r", stdin);

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    for( int j = 1; j <= n; ++j)
      scanf("%d", &g[i][j]);
  
  for (int u = 1; u <= n; ++u)
    dfs(u, u);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if(!vst[i][j] || !vst[1][j]) {
        putchar('N');
      }else {
        fill(mrk+1, mrk+n+1, 0);
        putchar(reach(1, j, i) ? 'N' : 'Y');
      }
    }
    putchar('\n');
  }

  return 0;
}