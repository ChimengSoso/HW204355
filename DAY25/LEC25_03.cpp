/**
 *    author:  ChimengSoso
 *    created: Tue Apr 30 2019 00:01:10
 *    file:    LEC25_03.cpp
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  int tc; scanf("%d", &tc);
  while (tc--) {
    char rlt = 'Y';
    int n; scanf("%d", &n);
    
    using pdd = pair<double, double>;
    
    auto dst = [&](pdd a, pdd b) {
      return (double)hypot(a.first-b.first, a.second-b.second);
    };
    
    vector<pdd> p(n);
    for (int i = 0; i < n; ++i) {
      double x, y; scanf("%lf%lf", &x, &y);
      p[i] = make_pair(x, y);  
    }
    
    double r;
    scanf("%lf", &r); r *= 2.0;

    for (int i = 0; i < n-1; ++i) {
      for (int j = i+1; j < n; ++j) {
        double d = dst(p[i], p[j]);
        if (d > r) {
          rlt = 'N'; break;
        }
      }
      if (rlt == 'N') break;
    }
    printf("%c\n", rlt);
  }
  return 0;
}