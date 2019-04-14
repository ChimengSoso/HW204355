/**
 *    author:  ChimengSoso
 *    created: Thu Jan 17 2019 12:21:10
 *    file:    LEC04_05.cpp
**/
#include <bits/stdc++.h>
#define F first
#define S second
#define pii pair<int, int>

using namespace std;
int main() {
  // freopen("input.txt", "r", stdin);
  int n; cin >> n;
  pair<int, int> *a = new pair<int, int>[n];
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    a[i] = make_pair(x, y);
  }
  sort(a, a+n, [&](pii p, pii q) {
    return p.S < q.S;
  });
  int rlt = 1, k = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i].F >= a[k].S) {
      rlt ++;
      k = i;
    }
  }
  cout << rlt;
  return 0;
}