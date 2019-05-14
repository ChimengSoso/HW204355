#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1.0)
const double EPS = 1e-9;

struct point { double x, y;   // only used if more precision is needed
  point() { x = y = 0.0; }                      // default constructor
  point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
  bool operator == (point other) const {
   return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };

struct vec { double x, y;  // name: `vec' is different from STL vector
  vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) {       // convert 2 points to vector a->b
  return vec(b.x - a.x, b.y - a.y); }

double dist(point p1, point p2) {                // Euclidean distance
  return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double angle(point a, point o, point b) {  // returns angle aob in rad
  vec oa = toVec(o, a), ob = toVec(o, b);
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))); }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool ccw(point p, point q, point r) {
  return cross(toVec(p, q), toVec(p, r)) > 0; }

bool isInLine(point p, point a, point b) {
  // check point p is in line(a, b)
  double len_cross = cross(toVec(a, p), toVec(p, b));
  if (fabs(len_cross) < EPS) {
    bool isIn_X_Axis = min(a.x, b.x) <= p.x and p.x <= max(a.x, b.x);
    bool isIn_Y_Axis = min(a.y, b.y) <= p.y and p.y <= max(a.y, b.y);
    return isIn_X_Axis && isIn_Y_Axis;
  } else {
    return false;
  }
}

bool isInBound(point pt, const vector<point> &P) {
  for (int i = 0; i < P.size() - 1; ++i) {
    if (isInLine(pt, P[i], P[i+1])) {
      return true;
    }
  }
  return false;
}

// returns true if point p is in either convex/concave polygon P
bool inPolygon(point pt, const vector<point> &P) {
  double sum = 0;    // assume the first vertex is equal to the last vertex
  for (int i = 0; i < (int)P.size()-1; i++) {
    double ag = angle(P[i], pt, P[i+1]);
    if (ccw(pt, P[i], P[i+1])) {
      sum += ag;                   // left turn/ccw
    } else {
      sum -= ag;                   // right turn/cw
    }
  }
  
  bool inPolygon = fabs(fabs(sum) - 2*PI) < EPS;
  bool inBound = isInBound(pt, P);

  return  inPolygon || inBound;
}

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
  return fabs(cross(toVec(p, q), toVec(p, r))) < EPS; }

point pivot;
bool angleCmp(point a, point b) {                 // angle-sorting function
  if (collinear(pivot, a, b))                               // special case
    return dist(pivot, a) < dist(pivot, b);    // check which one is closer
  double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
  double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
  return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; }   // compare two angles

vector<point> CH(vector<point> P) {   // the content of P may be reshuffled
  int i, j, n = (int)P.size();
  if (n <= 3) {
    if (!(P[0] == P[n-1])) P.push_back(P[0]); // safeguard from corner case
    return P;                           // special case, the CH is P itself
  }

  // first, find P0 = point with lowest Y and if tie: rightmost X
  int P0 = 0;
  for (i = 1; i < n; i++)
    if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
      P0 = i;

  point temp = P[0]; P[0] = P[P0]; P[P0] = temp;    // swap P[P0] with P[0]

  // second, sort points by angle w.r.t. pivot P0
  pivot = P[0];                    // use this global variable as reference
  sort(++P.begin(), P.end(), angleCmp);              // we do not sort P[0]

  // third, the ccw tests
  vector<point> S;
  S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);   // initial S
  i = 2;                                         // then, we check the rest
  while (i < n) {           // note: N must be >= 3 for this method to work
    j = (int)S.size()-1;
    if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);  // left turn, accept
    else S.pop_back(); }   // or pop the top of S until we have a left turn
  return S; }                                          // return the result

int main() {
  ios::sync_with_stdio(false);
  cin.tie();

  // freopen("input.txt", "r", stdin);
  
  int c, r, o; cin >> c >> r >> o;
  vector<point> point_c;
  for (int i = 0; i < c; ++i) {
    double x, y; cin >> x >> y;
    point_c.push_back(point(x, y));
  }
  vector<point> police;
  if (point_c.size() > 0)
    police = CH(point_c);

  vector<point> point_r;
  for (int i = 0; i < r; ++i) {
    double x, y; cin >> x >> y;
    point_r.push_back(point(x, y));
  }
  vector<point> rob;
  if (point_r.size() > 0)
    rob = CH(point_r);
  
  for (int i = 0; i < o; ++i) {
    double x, y; cin >> x >> y;
    point p(x, y);
    bool isInPolice = point_c.size() >= 3 and inPolygon(p, police);
    if (isInPolice) {
      printf("Citizen at (%.0f,%.0f) is safe.\n", x, y);
    } else {
      bool isInBandit = point_r.size() >= 3 and inPolygon(p, rob);
      if (isInBandit) {
        printf("Citizen at (%.0f,%.0f) is robbed.\n", x, y);
      } else {
        printf("Citizen at (%.0f,%.0f) is neither.\n", x, y);
      }
    }
  }
  return 0;
}