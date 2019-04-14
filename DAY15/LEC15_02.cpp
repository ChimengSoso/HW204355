/**
 *    author:  ChimengSoso
 *    created: Sun Feb 24 2019 14:14:2
 *    file:    LEC15_02.cpp
**/
#include <bits/stdc++.h>
#define um unordered_map
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  int n; scanf("%d", &n);
  
  vector<int> p(n+1), w(n+1);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d", &p[i], &w[i]);
  
  um<int, um<int, int>> t;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 30; ++j) {
      if (j < w[i]) t[i-1][j-w[i]] = -2e9;
      t[i][j] = max(t[i-1][j], t[i-1][j-w[i]] + p[i]);
    }
  }

  int g; scanf("%d", &g);
  int ans = 0;
  while (g--) {
    int mw; scanf("%d", &mw);
    ans += t[n][mw];
  }
  
  printf("%d", ans);
  return 0;
}