/**
 *    author:  ChimengSoso
 *    created: Tue Jan 15 2019 21:45:35
 *    file:    LEC03_02.cpp
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// sol: Divide and Conquer
ll mxSub(int l, int r, int* a) {
  if (l >= r) return max(0, a[r]);
  int m = (l+r)/2;
  
  ll mxLR = mxSub(l, m, a);
  mxLR = max(mxLR, mxSub(m+1, r, a));

  ll preR = 0, sufL = 0, sm = 0;
  
  for (int i = m+1; i <= r; ++i) {
    sm += a[i];
    preR = max(preR, sm);
  }
  sm = 0;
  for (int i = m; i >= l; --i) {
    sm += a[i];
    sufL = max(sufL, sm);
  }

  return max(sufL+preR, mxLR);
}

int main() {
  // freopen("input.txt", "r", stdin);
  
  int n; cin >> n; int* a = new int[n+1];
  for (int i = 1; i <= n; ++i)
    scanf("%d", a+i);

  printf("%lld", mxSub(1, n, a));
  return 0;
}