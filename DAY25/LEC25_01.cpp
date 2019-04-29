/**
 *    author:  ChimengSoso
 *    created: Mon Apr 29 2019 21:31:55
 *    file:    LEC25_01.cpp
**/
#include <bits/stdc++.h>
using namespace std;

struct point {
  double x, y;
  point() {}
  point(int x, int y) : x(x), y(y) {}
};

double cross(point a, point b, point c) { // ca x cb = real val in one direction
  return (a.x-c.x) * (b.y-c.y) - (b.x-c.x) * (a.y-c.y);
}

bool PointInTriangle(point p, point a, point b, point c) {
  double d1 = cross(p, a, b);
  double d2 = cross(p, b, c);
  double d3 = cross(p, c, a);

  bool has_neg = (d1 < 0.0) || (d2 < 0.0) || (d3 < 0.0);
  bool has_pos = (d1 > 0.0) || (d2 > 0.0) || (d3 > 0.0);

  return !(has_neg && has_pos);
}

int main() {
  freopen("input.txt", "r", stdin);
  int c, r, o; scanf("%d%d%d", &c, &r, &o);
  vector<point> pc(c);
  vector<point> pr(r);
  vector<bool> safe(o);
  vector<bool> robbed(o);
  
  for (int i = 0; i < c; ++i) {
    int x, y; scanf("%d%d", &x, &y);
    pc[i] = point(x, y);
  }
  for (int i = 0; i < r; ++i) {
    int x, y; scanf("%d%d", &x, &y);
    pr[i] = point(x, y);
  }

  for (int T = 0; T < o; ++T) {
    int x, y; scanf("%d%d", &x, &y);
    point pt(x, y);

    bool isSafe = false;
    for (int i = 0; i < c-2; ++i) {
      for (int j = i+1; j < c-1; ++j) {
        for (int  k = j+1; k < c; ++k) {
          if (PointInTriangle(pt, pc[i], pc[j], pc[k])) {
            isSafe = true;
            break;
          }
        }
        if (isSafe) break;
      }
      if (isSafe) break;
    }

    bool isRobbed = false;
    if (!isSafe) {
      for (int i = 0; i < r-2; ++i) {
        for (int j = i+1; j < r-1; ++j) {
          for (int  k = j+1; k < r; ++k) {
            if (PointInTriangle(pt, pr[i], pr[j], pr[k])) {
              isRobbed = true;
              break;
            }
          }
          if (isRobbed) break;
        }
        if (isRobbed) break;
      }
    }

    printf("Citizen at (%d,%d) is ", x, y);
    if (isSafe) puts("safe.");
    else if (isRobbed) puts("robbed.");
    else printf("neither.");
  }
  
  return 0;
}