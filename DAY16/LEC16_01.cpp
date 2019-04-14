/**
 *    author:  ChimengSoso
 *    created: Wed Feb 27 2019 21:6:21
 *    file:    LEC16_01.cpp
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  string x, y;
  cin >> x >> y;
  int n = x.length(), m = y.length();
  map<int, map<int, int>> t;
  for (int i = 0; i <= n; ++i) t[i][0] = i;
  for (int j = 0; j <= m; ++j) t[0][j] = j;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (x[i-1] == y[j-1]) {
        t[i][j] = t[i-1][j-1];
      } else {
        t[i][j] = min(t[i-1][j], min(t[i][j-1], t[i-1][j-1])) + 1;
      }
    }
  }
  cout << t[n][m] << ' ' << (t[n][m] < (1+max(n, m))/2);
  return 0;
}