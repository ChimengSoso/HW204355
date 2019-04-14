/**
 *    author:  ChimengSoso
 *    created: Wed Feb 13 2019 0:37:50
 *    file:    LEC11_03.cpp
**/
#include <bits/stdc++.h>
using namespace std;

int a[13], id[13], n;

void combi(int idx, int k) {
  if (k == 6) {
    for (int i = 1; i <= k; ++i)
      printf("%d ", a[id[i]]);
    printf("\n");
  } else {
    for (int i = 1; i <= n; ++i) {
      if (a[i] > a[id[k]]) {
        id[idx] = i;
        combi(idx+1, k+1);
      }
    }
  }
}

int main() {
  // freopen("input.txt", "r", stdin);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);
  sort(a+1, a+n+1);
  combi(1, 0);
  return 0;
}