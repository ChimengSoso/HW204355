/**
 *    author:  ChimengSoso
 *    created: Sat Mar 30 2019 1:52:31
 *    file:    LEC19_01_v2.cpp
**/
#include <bits/stdc++.h>
#define mt make_tuple
#define mp make_pair

using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using priority_q = priority_queue<iii, vector<iii>, greater<iii>>;

const int INF = 2e9;
const int N = 1005;
const int V = 105;

int dst[N][V], cst[N];
bool vst[N][V];
vector<ii> g[N];

priority_q pq;

int main() {
  freopen("input.txt", "r", stdin);
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &cst[i]);
  for (int i = 0; i < m; ++i) {
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
    g[u].push_back(mp(v, w));
    g[v].push_back(mp(u, w));
  }
  int q; scanf("%d", &q);
  for (int _ = 0; _ < q; ++_) {
    int c, st, ed; scanf("%d%d%d", &c, &st, &ed);

    pq = priority_q();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= c; ++j) {
        dst[i][j] = INF;
        vst[i][j] = false;
      }
    }
    
    // initialization

    dst[st][0] = 0;
    pq.push(mt(dst[st][0], st, 0));

    // run dijkstra's algorithm on search space graph
    while (!pq.empty()) {
      auto U = pq.top(); pq.pop();
      int u, cur_oil; tie(ignore, u, cur_oil) = U;

      if (vst[u][cur_oil]) continue;
      vst[u][cur_oil] = true;
      if (u == ed && cur_oil == 0) break;

      int du = dst[u][cur_oil];

      for (auto V : g[u]) {
        int v = V.first;
        int w = V.second;

        if (cur_oil <= c) {
          int nxt = cur_oil - w;
          if (nxt < 0 || vst[v][nxt]) continue;
          if (du < dst[v][nxt]) {
            dst[v][nxt] = du;
            pq.push(mt(dst[v][nxt], v, nxt));
          }
        }

      }
      int nxt = cur_oil + 1;
      if (nxt <= c) {
        if (vst[u][nxt]) continue;
        if (du + cst[u] < dst[u][cur_oil+1]) {
          dst[u][cur_oil+1] = du + cst[u];
          pq.push(mt(dst[u][cur_oil+1], u, cur_oil+1));
        }
      }
    }

    if (vst[ed][0])
      printf("%d\n", dst[ed][0]);
    else
      printf("impossible\n");
  }
  return 0;
}