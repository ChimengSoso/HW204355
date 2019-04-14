/**
 *    author:  ChimengSoso
 *    created: Wed Feb 27 2019 21:27:01
 *    file:    LEC16_02.cpp
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  int L, n; scanf("%d%d", &L, &n);
  vector<int> pos(n+2);
  pos[0] = 0; pos[n+1] = L;
  for (int i = 1; i <= n; ++i)
    scanf("%d", &pos[i]);
  sort(pos.begin(), pos.end());
  map<int, map<int, int>> t; n += 2;
  for (int s = 3; s <= n; ++s) {
    for (int i = 0; i <= n-s; ++i) {
      int j = i+s-1;
      t[i][j] = 1e9;
      for (int k = i+1; k < j; ++k)
        t[i][j] = min(t[i][j], t[i][k] + t[k][j] + pos[j] - pos[i]);
    }
  }
  printf("%d\n", t[0][n-1]);
  return 0;
}