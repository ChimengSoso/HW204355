/**
 *    author:  ChimengSoso
 *    created: Sun Apr 21 2019 0:31:38
 *    file:    LEC24_01.cpp
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  int x, y, z;
  vector<tuple<int, int, int>> p;
  while (cin >> x >> y >> z, x || y || z)
    p.push_back(make_tuple(x, y, z));
  
  int n = p.size();
  int htg[15] = {};

  for (int i = 0; i < n; ++i) {
    int mn_dst = 1e9;
    for (int j = 0; j < n; ++j) {
      if (j == i) continue;
      int dx = get<0>(p[i]) - get<0>(p[j]);
      int dy = get<1>(p[i]) - get<1>(p[j]);
      int dz = get<2>(p[i]) - get<2>(p[j]);
      int dst = (int) sqrt(dx*dx + dy*dy + dz*dz);
      if (dst > 10) continue;
      mn_dst = min(mn_dst, dst);
    }
    if (mn_dst != (int) 1e9)
      htg[mn_dst]++;
  }
  for (int i = 0; i < 10; ++i)
    printf("%d ", htg[i]);
  return 0;
}