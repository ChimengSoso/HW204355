/**
 *    author:  ChimengSoso
 *    created: Thu Jan 17 2019 11:53:11
 *    file:    LEC04_02.cpp
**/
#include <bits/stdc++.h>
using namespace std;
bool sieve[10005];
int main() {
  // freopen("input.txt", "r", stdin);
  int n = 10000;
  fill(sieve, sieve+n+1, 1);
  sieve[0] = sieve[1] = 0;
  for (int i = 2; i <= n; ++i) {
    if (sieve[i]) {
      for (int j = i+i; j <= n; j += i)
        sieve[j] = 0;
    }
  }
  int a, b, sm = 0; cin >> a >> b;
  for (int i = a; i <= b; ++i) {
    sm += sieve[i];
  }
  cout << sm;
  return 0;
}