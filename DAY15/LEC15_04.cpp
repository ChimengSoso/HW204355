/**
 *    author:  ChimengSoso
 *    created: Sun Feb 24 2019 14:58:21
 *    file:    LEC15_04.cpp
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  int n, k; scanf("%d%d", &n, &k);
  vector<int> t(n+1, 0), c(k);
  for (int i = 0; i < k; ++i) 
    scanf("%d", &c[i]);
  for (int i = 1; i <= n; ++i) {
    t[i] = 1e9;
    for (int j = 0; j < k; ++j) {
      if (i >= c[j])  
        t[i] = min(t[i], t[i-c[j]] + 1);
    }
  }
  printf("%d", t[n]);
  return 0;
}