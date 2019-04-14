/**
 *    author:  ChimengSoso
 *    created: Sun Feb 24 2019 14:1:15
 *    file:    LEC15_01.cpp
**/
#include <bits/stdc++.h>
using namespace std;
int main() {
  // freopen("input.txt", "r", stdin);
  int n; scanf("%d", &n);
  
  vector<int> v(n);
  int sm = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
    sm += v[i];
  }
  
  if (sm % 2 == 1) return printf("NO"), 0;
  sm /= 2;
  
  bool *ss = new bool[sm+1](); ss[0] = true;
  for (int i = 0; i < n; ++i) {
    for (int w = sm; w >= 0; --w) {
      if (w + v[i] <= sm && ss[w])
        ss[w+v[i]] = true;
    }
  }
  
  printf("%s", ss[sm] ? "YES" : "NO");
  return 0;
}