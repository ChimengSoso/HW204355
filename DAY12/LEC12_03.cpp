/**
 *    author:  ChimengSoso 
 *    created: 2019-02-14 23:13:31 
**/
#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const int M = 'z'+1;
char a[N+1][N+1];
int LU[M][N][N], RU[M][N][N], LD[M][N][N], RD[M][N][N];
inline int min(int x, int y, int z) { return min(min(x, y), z); }
int main() {
  // freopen("input.txt", "r", stdin);
  int n, m, q; scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; ++i)
    scanf(" %s", a[i]+1);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int ir = n-i+1, jr = m-j+1;
      char c = a[i][j], cir = a[ir][j], cjr = a[i][jr], cijr = a[ir][jr];
      
      LU[c][i][j] = min(LU[c][i-1][j-1], LU[c][i-1][j], LU[c][i][j-1])+1;
      RU[cjr][i][jr] = min(RU[cjr][i-1][jr+1], RU[cjr][i-1][jr], RU[cjr][i][jr+1])+1;
      LD[cir][ir][j] = min(LD[cir][ir+1][j-1], LD[cir][ir+1][j], LD[cir][ir][j-1])+1;
      RD[cijr][ir][jr] = min(RD[cijr][ir+1][jr+1], RD[cijr][ir+1][jr], RD[cijr][ir][jr+1])+1;
    }
  }

  while (q--) {
    int r, c; scanf("%d%d", &r, &c);  ++r, ++c; char s = a[r][c];
    int rlt = min(min(LU[s][r][c], RU[s][r][c]), min(LD[s][r][c], RD[s][r][c]));
    printf("%d\n", rlt*2-1);
  }
  return 0;
}