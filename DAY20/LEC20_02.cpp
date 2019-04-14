#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int findRoot(vi& p, int u) {
  return p[u] = (u == p[u] ? u : findRoot(p, p[u]));
}

int main() {
  // freopen("input.txt", "r", stdin);
  int n, m; scanf("%d%d", &n, &m);

  vi sz(n+1);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &sz[i]);

  vi p(n+1); iota(p.begin(), p.end(), 0);

  while (m--) {
    int u, v; scanf("%d%d", &u, &v);

    u = findRoot(p, u);
    v = findRoot(p, v);

    if (u == v) { printf("-1\n"); continue; }
    if (sz[u] < sz[v] || (sz[u] == sz[v] && u > v))
      swap(u, v);

    printf("%d\n", u);
    sz[u] += sz[v]/2;
    p[v] = u;
  }
  return 0;
}
