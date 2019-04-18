/**
 *    author:  ChimengSoso 
 *    created: 2019-04-18 18:20:18 
**/

#include <bits/stdc++.h>
using namespace std;

char S[55][55], P[55];
int n, m;

int dx[] = {1, -1, -1,  1,  0, -1, 0, 1};
int dy[] = {1, -1,  1, -1, -1,  0, 1, 0};

bool find(int idx, int len, int r, int c, int dr, int dc) {
  if (idx == len) return true;
  if (r < 0 || c < 0 || r >= n || c >= m) return false;
  if (tolower(P[idx]) != tolower(S[r][c])) return false;
  return find(idx+1, len, r+dr, c+dc, dr, dc);
}

int main() {
  // freopen("input.txt", "r", stdin);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf(" %s", S[i]);
  }
  int k; scanf("%d", &k);
  while (k--) {
    scanf(" %s", P);
    int len = strlen(P);
    bool found = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        for (int k = 0; k < 8 && !found; ++k)
          found = find(0, len, i, j, dx[k], dy[k]);
        if (!found) continue;
        printf("%d %d\n", i+1, j+1);
        break;
      }
      if (found) break;
    }
  }

  return 0;
}