/**
 *    author:  ChimengSoso
 *    created: Mon Apr 29 2019 20:44:46
 *    file:    LEC24_03.cpp
**/
#include <bits/stdc++.h>
using namespace std;

struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}
};

struct vec {
  double x, y;
  vec(double x, double y) : x(x), y(y) {}
};

vec toVec(point a, point b) {
  return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s) {
  return vec(v.x * s, v.y * s);
}

point translate(point p, vec v) {
  return point(p.x+v.x, p.y + v.y);
}

double dot(vec a, vec b) {
  return a.x * b.x + a.y * b.y;
}

double norm_sq(vec v) { // |v|^2
  return dot(v, v);
}

double dist(point a, point b) {
  return hypot(a.x - b.x, a.y - b.y);
}

double distToLineSegment(point p, point a, point b, point &c) {
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  if (u < 0.0) {
    c = point(a.x, a.y);
    return dist(p, a);
  }
  if (u > 1.0) {
    c = point(b.x, b.y);
    return dist(p, b);
  }
  c = translate(a, scale(ab, u));
  return dist(p, c);
}

int main() {
  // freopen("input.txt", "r", stdin);
  
  double s, e; scanf("%lf%lf", &s, &e);
  point origin(s, e);

  int n; scanf("%d", &n);

  double minDSt = 1e18;
  point pt(s, e);
  point rlt = pt;
  
  point cur, prv;
  for (int i = 0; i <= n; ++i) {
    double x, y; scanf("%lf%lf", &x, &y);
    cur = point(x, y);
    if (i != 0) {
      double dst = distToLineSegment(origin, prv, cur, pt);
      if (dst < minDSt) {
        minDSt = dst;
        rlt = pt;
      }
    }
    prv = cur;
  }

  printf("%.4f\n%.4f\n", rlt.x, rlt.y);
  return 0;
}