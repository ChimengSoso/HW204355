/**
 *    author:  ChimengSoso
 *    created: Thu Jan 24 2019 17:7:37
 *    file:    LEC06_02.cpp
**/
#include <bits/stdc++.h>
using namespace std;
bool t[1234];
bool tmp[1234];
int main() {
  // freopen("input.txt", "r", stdin);
  int n, m; cin >> n >> m;
  fill(t, t+(1<<n), 1);
  for (int i = 0; i < m; ++i) {
    int c; scanf("%d",  &c);
    t[c-1] = 0;
  }
  int r = 1 << n;
  int rlt = 0;
  while (r != 1) {
    for (int i = 0; i < r; i += 2) {
      tmp[(i+i+1)/4] = t[i] | t[i+1];
      rlt += t[i] ^ t[i+1];
    }
    r >>= 1;
    copy(tmp, tmp + r, t);
  }
  cout << rlt;
  return 0;
}