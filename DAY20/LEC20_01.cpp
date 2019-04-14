#include <bits/stdc++.h>
#define mt make_tuple
using namespace std;

using iii = tuple<int, int, int>; // {cost, u, v}
using vi = vector<int>;

int findRoot(vi& p, int u) {
  return p[u] = (u == p[u] ? u : findRoot(p, p[u]));
}

int isSame(vi p, int u, int v) {
  return findRoot(p, u) == findRoot(p, v);
}

void unionSet(vi& p, int u, int v) {
  u = findRoot(p, u);
  v = findRoot(p, v);
  if (u != v)
    p[u] = v;
}

int main() {
  // freopen("input.txt", "r", stdin);

  int n; scanf("%d", &n);
  vector<iii> ET(n-1);
  for (int i = 0; i < n-1; ++i) {
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
    ET[i] = mt(w, u, v);
  }

  int k; scanf("%d", &k);
  vector<iii> EK;
  for (int i = 0; i < k; ++i) {
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
    EK.push_back(mt(w, u, v));
  }

  int m; scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
    ET.push_back(mt(w, u, v));
  }

  sort(ET.begin(), ET.end());

  vi p(n+1);
  iota(p.begin(), p.end(), 0);

  int cstT = 0;
  for (int i = 0; i < ET.size(); ++i) {
    int u, v, w; tie(w, u, v) = ET[i]; // initialization
    if (!isSame(p, u, v)) {
      cstT += w;
      unionSet(p, u, v);
    }
  }

  ET.insert(ET.end(), EK.begin(), EK.end());
  sort(ET.begin(), ET.end());

  iota(p.begin(), p.end(), 0);

  int cstT2 = 0;
  for (int i = 0; i < ET.size(); ++i) {
    int u, v, w; tie(w, u, v) = ET[i]; // initialization
    if (!isSame(p, u, v)) {
      cstT2 += w;
      unionSet(p, u, v);
    }
  }

  printf("%d\n%d\n", cstT, cstT2);
  return 0;
}
