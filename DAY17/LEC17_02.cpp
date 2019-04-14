/**
 *    author:  ChimengSoso
 *    created: Mon Mar 18 2019 00:06:16
 *    file:    LEC17_02.cpp
**/
#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> g;

void dfs(map<int, bool>& vst, int u, int ttl) {
  if (ttl < 0) return;
  if (vst[u]) return;
  vst[u] = true;

  for (auto v : g[u])
    dfs(vst, v, ttl-1);
    
  vst[u] = false;
}

int main() {
  freopen("input.txt", "r", stdin);
  int n; scanf("%d", &n);
  
  set<int> V;

  while (n--) {
    int u, v; scanf("%d%d", &u, &v);
    g[u].insert(v); g[v].insert(u);
    V.insert(u); V.insert(v);
  }

  int node, ttl;
  while (scanf("%d%d", &node, &ttl), node || ttl ) {
    if (!V.count(node)) {
      printf("%d\n", V.size());
      V.insert(node);
      continue;
    } 
    map<int, bool> vst;
    dfs(vst, node, ttl);
    int rlt = V.size() - vst.size();
    printf("%d\n", rlt);
  }
  return 0;
}