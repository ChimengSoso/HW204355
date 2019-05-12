/**
 *    author:  ChimengSoso
 *    created: Tue Apr 30 2019 00:01:10
 *    file:    LEC25_03.cpp
**/
#include <bits/stdc++.h>
using namespace std;

struct point {
  double x, y;
  point() { x = y = 0.0; }
  point(double x, double y) : x(x), y(y) {}
};

bool isInCircle(point p, point c, double r) {
  // check point 'p' is in the circle center point 'c' with radius 'r'
  double dy = p.y - c.y;
  double dx = p.x - c.x;
  double Euc = dx * dx + dy * dy;
  double rSq = r * r;
  return Euc <= rSq;
}

bool canBeCircle(point a, point b, double r, point& c) {
  double d2 = hypot(a.x - b.x, a.y - b.y); d2 *= d2;
  double det = r*r / d2 - 0.25;
  if (det < 0.0) return false;
  double h = sqrt(det);
  c.x = (a.x + b.x)*0.5 + (a.y - b.y) * h;
  c.y = (a.y + b.y)*0.5 + (b.x - a.x) * h;
  return true;
}

int main() {
  freopen("input.txt", "r", stdin);
  int tc; scanf("%d", &tc);
  while (tc--) {
    char rlt = 'N';
    int n; scanf("%d", &n);
    
    vector<point> p(n);
    for (int i = 0; i < n; ++i) {
      double x, y; scanf("%lf%lf", &x, &y);
      p[i] = point(x, y);
    }
    
    double r;
    scanf("%lf", &r);
    for (int i = 0; i < n-1; ++i) {
      for (int j = i+1; j < n; ++j) {
        point c;
        if (canBeCircle(p[i], p[j], r, c)) {
          bool isAllInside = true;
          for (int k = 0; k < n; ++k) {
            if (!isInCircle(p[k], c, r)) {
              isAllInside = false;
              break;
            }
          }
          if (isAllInside) {
            rlt = 'Y';
            break;
          }
        }
      }
      if (rlt == 'N') break;
    }
    printf("%c\n", rlt);
  }
  return 0;
}