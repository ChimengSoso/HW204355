/**
 *    author:  ChimengSoso
 *    created: Tue Apr 30 2019 12:41:26
 *    file:    CheckOrientation.cpp
**/
#include <bits/stdc++.h>
using namespace std;

struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
};

void statusOrientation(Point a, Point b, Point c) {
  // line a -> b and b -> c : b is center of checking
  double i = b.x - a.x, j = b.y - a.y;
  double k = c.x - b.x, l = c.y - b.y;
  double cross_len = i * l - k * j;
  if (cross_len > 0.0) 
    printf("Counter Clockwise!\n");
  else if (cross_len < 0.0) 
    printf("Clockwise!\n");
  else
    printf("Collinear\n");
}

int main() {
  freopen("input.txt", "r", stdin);
  int n = 4;
  Point p[n];
  for (int i = 0; i < n; ++i) {
    double x, y; scanf("%lf%lf", &x, &y);
    p[i] = Point(x, y);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      for (int k = 0; k < n; ++k) {
        if (k == i or k == j) continue;
        printf("(%.0lf, %.0lf) to (%.0lf, %.0lf) to (%.0lf, %.0lf) is ",
        p[i].x, p[i].y, p[j].x, p[j].y, p[k].x, p[k].y);
        statusOrientation(p[i], p[j], p[k]);
      }
    }
  }
  return 0;
}