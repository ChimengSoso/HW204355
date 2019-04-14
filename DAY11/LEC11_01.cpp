/**
 *    author:  ChimengSoso 
 *    created: 2019-02-13 00:32:54 
**/
#include <bits/stdc++.h>
using namespace std;
int main() {
  // freopen("input.txt", "r", stdin);
  int a, b, c; cin >> a >> b >> c;
  for (int x = -22; x <= 22; ++x) {
    for (int y = -22; y <= 22; ++y) {
      int z = a-x-y;
      if (x+y+z == a && x*y*z == b && x*x + y*y + z*z == c
          && x != y && y != z && z != x) {
        int mn = min(min(x, y), z);
        int mx = max(max(x, y), z);
        int md = x+y+z - mn - mx;
        printf("%d %d %d\n", mn, md, mx);
        return 0;
      }
    }
  }
  printf("No solution.");
  return 0;
}