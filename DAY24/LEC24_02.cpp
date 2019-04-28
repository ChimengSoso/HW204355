/**
 *    author:  ChimengSoso
 *    created: Sun Apr 21 2019 1:0:21
 *    file:    LEC24_02.cpp
**/
#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {};
  point(const point& s) : x(s.x), y(s.y) {};
};

struct line {
  double a, b, c;
  point ps, pe; // point start, point end
  line() {}
  line(point s, point t) {
    ps = s, pe = t;
    if (fabs(s.x - t.x) < eps)
      a = 1.0, b = 0.0, c = -s.x;
    else {
      a = -(s.y - t.y) / (s.x - t.x);
      b = 1.0;
      c = (-a) * s.x - s.y;
    }
  }
};

bool isPrl(line L, line R) { // is parallel of 2 line
  return fabs(L.a-R.a) < eps && fabs(L.b-R.b) < eps;
}

bool findIntersectPoint(line L, line R, point& p) {
  if (isPrl(L, R)) return false;
  p.x = (R.b * L.c - L.b*R.c) / (R.a * L.b - L.a * R.b);
  if (fabs(L.b) < eps) L = R;
  p.y = -(L.a * p.x + L.c);
  return true;
}

bool inLine(line l, point p) {
  point s(l.ps);
  point e(l.pe);
  double mnx = min(s.x, e.x);
  double mny = min(s.y, e.y);
  double mxx = max(s.x, e.x);
  double mxy = max(s.y, e.y);
  return (mnx < p.x or fabs(mnx-p.x) < eps) and (p.x < mxx or fabs(mxx-p.x) < eps) and 
         (mny < p.y or fabs(mny-p.y) < eps) and (p.y < mxy or fabs(mxy-p.y) < eps);
}

bool intersect(line L, line R) {
  point p;
  bool isIntersect = findIntersectPoint(L, R, p);
  if (!isIntersect) return false;
  return inLine(L, p) and inLine(R, p);
}

int main() {
  // freopen("input.txt", "r", stdin);
  int tc; scanf("%d", &tc);
  while (tc--) {
    double psx, psy, pex, pey; // point start/end x/y
    double x1, y1, x2, y2;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &psx, &psy, &pex, &pey, &x1, &y1, &x2, &y2);

    double  xleft = min(x1, x2);
    double   ytop = max(y1, y2);
    double xright = max(x1, x2);
    double  ydown = min(y1, y2);

    line P(point(psx, psy), point(pex, pey));
    line L(point(xleft, ytop), point(xleft, ydown));
    line R(point(xright, ytop), point(xright, ydown));
    line T(point(xleft, ytop), point(xright, ytop));
    line D(point(xleft, ydown), point(xright, ydown));

    bool chk1 = intersect(P, L);
    bool chk2 = intersect(P, R);
    bool chk3 = intersect(P, T);
    bool chk4 = intersect(P, D);

    bool rlt = chk1 or chk2 or chk3 or chk4;
    printf("%c\n", rlt ? 'T' : 'F');
  }
  return 0;
}