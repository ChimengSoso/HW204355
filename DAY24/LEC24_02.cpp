/**
 *    author:  ChimengSoso
 *    created: Sun Apr 21 2019 1:0:21
 *    file:    LEC24_02.cpp
**/
#include <bits/stdc++.h>
#define mt make_tuple
#define vi vector<int>

using namespace std;

using line = tuple<int, int, int, int>; // x1, y1, x2, y2 
// type 'line' : mean line of point(x1, y1) to point(x2, y2)

using point = pair<int, int>;

int main() {
  freopen("input.txt", "r", stdin);
  int tc; scanf("%d", &tc);
  while (tc--) {
    int x1, y1, x2, y2, l, t, r, b;
    scanf("%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &l, &t, &r, &b);

    function<int(point, point)> cross_pdct = [&](point P1, point P2) {
      return P1.first * P2.second - P2.first * P1.second;
    };
    
    function<int(point, point, point)> direction = [&](point p1, point p2, point p3) {
      point sub31 = make_pair(p3.first - p1.first, p3.second - p1.second);
      point sub21 = make_pair(p2.first - p1.first, p2.second - p2.second);
      return cross_pdct(sub31, sub21);
    };

    function<bool(point, point, point)> on_segment = [&](point p1, point p2, point p)  {
      bool b1 = min(p1.first, p2.first) <= p.first;
      bool b2 = p.first <= max(p1.first, p2.first);
      bool b3 = min(p1.second, p2.second) <= p.second;
      bool b4 = p.second <= max(p1.second, p2.second);
      return b1 && b2 && b3 && b4;
    };
    
    function<bool(line, line)> intersect = [&](line L1, line L2) {
      point p1 = make_pair(get<0>(L1), get<1>(L1));
      point p2 = make_pair(get<2>(L1), get<3>(L1));
      point p3 = make_pair(get<0>(L2), get<1>(L2));
      point p4 = make_pair(get<2>(L2), get<3>(L2));
      
      int d1 = direction(p3, p4, p1);
      int d2 = direction(p3, p4, p2);
      int d3 = direction(p1, p2, p3);
      int d4 = direction(p1, p2, p4);

      if (((d1 > 0 and d2 < 0) or (d1 < 0 and d2 > 0)) and 
          ((d3 > 0 and d4 < 0) or (d3 < 0 and d4 > 0)))
            return true;
      else if (d1 == 0 and on_segment(p3, p4, p1))
        return true;
      else if (d2 == 0 and on_segment(p3, p4, p2))
        return true;
      else if (d3 == 0 and on_segment(p1, p2, p3))
        return true;
      else if (d4 == 0 and on_segment(p1, p2, p4))
        return true;
      else
        return false;
    };

    line real = mt(x1, y1, x2, y2);
    
    line bleft  = mt(l, t, l, b);
    line bright = mt(r, t, r, b);
    line btop   = mt(l, t, r, t);
    line bdown  = mt(l, b, r, b);

    bool chk_left  = intersect(real, bleft);
    bool chk_right = intersect(real, bright);
    bool chk_top   = intersect(real, btop);
    bool chk_down  = intersect(real, bdown);
    
    bool rlt = chk_left || chk_right || chk_top || chk_down;
    printf("%c\n", rlt ? 'T' : 'F');
  }
  return 0;
}