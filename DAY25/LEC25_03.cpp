/**
 *    author:  ChimengSoso 
 *    created: 2019-05-14 00:37:11 
**/
#include <bits/stdc++.h>
using namespace std;

struct Point {
  double x, y;
  Point() { x = y = 0.0; }
  Point(double x, double y) : x(x), y(y) {}
};

bool isInsideCircle(Point p, Point c, double r) {
  double dx = p.x - c.x,
         dy = p.y - c.y;
  double eqd = sqrt(dx*dx + dy*dy);
  return eqd <= r;
}

bool canBeCircle(Point a, Point b, double r, Point& c) {
  double d2 = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
  double det = r*r/d2 - 0.25;
  if (det < 0.0) return false;
  double h = sqrt(det);
  c.x = (a.x + b.x)*0.5 + (a.y - b.y)*h;
  c.y = (a.y + b.y)*0.5 + (b.x - a.x)*h;
  return true;
}

void sol(vector<Point>& p, double& r) {
  int n = p.size();
  bool allPointInside = false;
  for (int i = 0; i < n && !allPointInside; ++i) {
    for (int j = 0; j < n && !allPointInside; ++j) {
      if (i == j) continue;
      Point center;
      if (canBeCircle(p[i], p[j], r, center)) {
        allPointInside = true;
        for (int k = 0; k < n; ++k) {
          if (k == i || k == j) continue;
          if (!isInsideCircle(p[k], center, r)) {
            allPointInside = false;
            break;
          }
        }
      }
    }
  }
  printf("%c\n", allPointInside ? 'Y' : 'N');
}

int main() {
  // freopen("input.txt", "r", stdin);
  
  int tc; scanf("%d", &tc);
  while (tc--) {
  
    int n; scanf("%d", &n);
    vector<Point> point(n);
  
    for (int i = 0; i < n; ++i) {
      double x, y; scanf("%lf%lf", &x, &y);
      point[i] = Point(x, y);
    }
  
    double r; scanf("%lf", &r);
    sol(point, r);
  }

  return 0;
}