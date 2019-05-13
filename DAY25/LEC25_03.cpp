/**
 *    author:  ChimengSoso
 *    created: Tue Apr 30 2019 00:01:10
 *    file:    LEC25_03.cpp
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("input.txt", "r", stdin);
  int tc; scanf("%d", &tc);
  while (tc--) {
    char rlt = 'N';
    int n; scanf("%d", &n);
    
    using pdd = pair<double, double>;

    vector<pdd> p(n);
    for (int i = 0; i < n; ++i) {
      double x, y; scanf("%lf%lf", &x, &y);
      p[i] = pdd(x, y);
    }
    
    double r;
    scanf("%lf", &r);
    
    double diameter = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        double d = hypot(p[i].first - p[j].first, p[i].second - p[j].second);
        diameter = max(diameter, d);
      }
    }
    printf("%c\n", diameter < 2*r ? 'Y' : 'N');
  }
  return 0;
}