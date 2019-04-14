/**
 *    author:  ChimengSoso
 *    created: Thu Jan 17 2019 11:48:29
 *    file:    LEC04_01.cpp
**/
#include <bits/stdc++.h>
using namespace std;
bool sieve[10005];
int main() {
  // freopen("input.txt", "r", stdin);
  int n; cin >> n;
  fill(sieve, sieve+n+1, 1);
  sieve[0] = sieve[1] = 0;
  for (int i = 2; i <= n; ++i) {
    if (sieve[i]) {
      for (int j = i+i; j <= n; j += i)
        sieve[j] = 0;
    }
  }
  for (int i = 2; i <= n; ++i) {
    if (sieve[i]) printf("%d ", i);
  }
  return 0;
}