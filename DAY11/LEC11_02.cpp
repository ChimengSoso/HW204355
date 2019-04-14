/**
 *    author:  ChimengSoso
 *    created: Tue Feb 12 2019 22:56:0
 *    file:    LEC11_02.cpp
**/
#include <bits/stdc++.h>
using namespace std;

bool checkSame(int n, int *f) {
  int t = 5;
  while (t--) {
    f[n%10]++;
    n /= 10;
  }
  for (int i = 0; i < 10; ++i)
    if (f[i] > 1) return 0;
  return 1;
}

int main() {
  freopen("input.txt", "r", stdin);
  int n; scanf("%d", &n);
  bool isSol = false;
  int *f = new int[10];
  for (int i = n; i < 100000; ++i) {
    memset(f, 0, 10 * sizeof(int));
    if (i%n == 0 and checkSame(i, f) and checkSame(i/n, f)) {
      printf("%05d / %05d = %d\n", i, i/n, n);
      isSol = true;
    }
  }

  if (!isSol) {
    printf("There are no solutions for N.");
  }
  return 0;
}