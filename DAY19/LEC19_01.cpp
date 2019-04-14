/**
 *    author:  ChimengSoso
 *    created: Mon Mar 25 2019 22:27:48
 *    file:    LEC19_01.cpp
**/
#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;         // {node, wieght}
using iii = tuple<int, int, int>;  // {cost, node, oil}

const int INF = 2e9;
int main() {
  // freopen("input.txt", "r", stdin);
  
  int n, m; scanf("%d%d", &n, &m);

  vector<int> cst(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &cst[i]);

  vector<vector<ii>> g(n);
  for (int i = 1; i <= m; ++i) {
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
    g[u].emplace_back(v, w); g[v].emplace_back(u, w);
  }
  
  int q; scanf("%d", &q);
  while (q--) {
    int c, s, e; scanf("%d%d%d", &c, &s, &e);

    vector<vector<int>> dst(n, vector<int>(c+1, INF));
    vector<vector<bool>> vst(n, vector<bool>(c+1, false));

    dst[s][0] = 0;

    priority_queue<iii> pq; pq.push(make_tuple(-dst[s][0], s, 0));
    
    while (!pq.empty()) { // begin while loop
      auto U = pq.top(); pq.pop();
      
      int du, u, cur_oil; tie(du, u, cur_oil) = U; du = -du;
      
      if (vst[u][cur_oil]) continue;
      vst[u][cur_oil] = true;

      if (u == e and cur_oil == 0) break;

      for (auto V : g[u]) {
        int v = V.first;
        int w = V.second;
        int nxt = cur_oil - w;
        if (cur_oil > c || nxt < 0) continue;
        if (du < dst[v][nxt]) {
          dst[v][nxt] = du;
          pq.push(make_tuple(-du, v, nxt));
        }
      }
      
      int nxt = cur_oil + 1;
      if (nxt > c) continue;
      if (du + cst[u] < dst[u][nxt]) {
        dst[u][nxt] = du + cst[u];
        pq.push(make_tuple(-dst[u][nxt], u, nxt));
      }
    } // end while loop

    if (vst[e][0])
      printf("%d\n", dst[e][0]);
    else
      printf("impossible\n");
  }
  return 0;
}