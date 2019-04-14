/**
 *    author:  ChimengSoso
 *    created: Mon Feb 18 2019 15:57:35
 *    file:    LEC13_02.cpp
**/
#include <bits/stdc++.h>
using namespace std;
char brd[20][20];
int col[20];

bool chk(int k) {
  if (brd[col[k]][k] == '*') return 0;
  for (int i = 0; i < k; ++i) {
    if (abs(i-k) == abs(col[i]-col[k]))
      return 0;
  }
  return 1;
}

int sol(int n, int k = 0) {
  if (k == n) return 1;
  int rlt = 0;
  for (int i = k; i < n; ++i) {
    swap(col[i], col[k]);
    if (chk(k))
      rlt += sol(n, k+1);
    swap(col[i], col[k]);
  }
  return rlt;
}

int main() {
  // freopen("input.txt", "r", stdin);
  int q; scanf("%d", &q);
  while (q--) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      col[i] = i;
      scanf(" %s", &brd[i]);
    }
    printf("%d\n", sol(n));
  }
  return 0;
}