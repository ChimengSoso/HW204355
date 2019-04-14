/**
 *    author:  ChimengSoso
 *    created: Thu Jan 17 2019 12:1:31
 *    file:    LEC04_03.cpp
**/
#include <bits/stdc++.h>
using namespace std;
int main() {
  // freopen("input.txt", "r", stdin);
  int n; cin >> n;
  if (n == 1) return printf("1"), 0;
  int a[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384};
  int sz = sizeof(a) / sizeof(a[0]);
  for (int i = 0; i < sz; ++i) {
    if (2 * a[i] >= n)
      return printf("%d", i+2), 0;
  }
  return 0;
}