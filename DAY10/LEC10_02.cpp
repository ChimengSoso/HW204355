/**
 *    author:  ChimengSoso 
 *    created: 2019-02-10 12:36:13 
**/
#include <stdio.h>

int a[505][505];

class SMT {
private:
  int n, valExit;
  int** seg;
  int (* cal) (int, int);
public:
  SMT(int size, int ve, int (*f)(int, int)) : n(size), valExit(ve), cal(f) {
    seg = new int*[1024];
    for (int i = 0; i < 1024; ++i) {
      seg[i] = new int[1024]();
    }
    buildRow(1, n, 1);
  }

  void buildCol(int r, int c, int pRow, int b, int e, int p) {
    if (b == e) {
        if (r == c) {
          seg[pRow][p] = a[r][b];
        } else {
          // make seg tree in same col. So, use relative of Row
          seg[pRow][p] = cal(seg[pRow<<1][p], seg[pRow<<1|1][p]);
        }
    } else {
      int m = (b + e) / 2;
      buildCol(r, c, pRow, b, m, p << 1);
      buildCol(r, c, pRow, m+1, e, p << 1|1);

      // make seg tree in same row. So, use relative of Col
      seg[pRow][p] = cal(seg[pRow][p << 1] , seg[pRow][p << 1 | 1]);
    }
  }

  void buildRow(int b, int e, int p) {
    if (b == e) {
      buildCol(b, e, p, 1, n, 1);
    } else {
      int m = (b + e) / 2;
      buildRow(b, m, p << 1);
      buildRow(m+1, e, p << 1|1);
      buildCol(b, e, p, 1, n, 1);
    }
  }

  int queryCol(int pRow, int l, int r, int b, int e, int p) {
    if (b > e || b > r || e < l) return valExit;
    if (l <= b and e <= r) {
      return seg[pRow][p];
    } else {
      int m = (b + e) >> 1;
      int rlt1 = queryCol(pRow, l, r, b, m, p << 1);
      int rlt2 = queryCol(pRow, l, r, m+1, e, p<<1|1);
      return cal(rlt1, rlt2);
    }
  }

  int queryRow(int r1, int c1, int r2, int c2, int b, int e, int p) {
    if (b > e || b > r2 || e < r1) return valExit;
    if (r1 <= b and e <= r2) {
      return queryCol(p, c1, c2, 1, n, 1);
    } else {
      int m = (b + e) >> 1;
      int rlt1 = queryRow(r1, c1, r2, c2, b, m, p << 1);
      int rlt2 = queryRow(r1, c1, r2, c2, m+1, e, p << 1|1);
      return cal(rlt1, rlt2);
    }
  }

  int query(int r1, int c1, int r2, int c2) {
    return queryRow(r1, c1, r2, c2, 1, n, 1);
  }

  void updateCol(int pRow, int x, int y, int val, int r1, int r2, int b, int e, int p) {
    if (b == e) {
      if (r1 == r2) {
        seg[pRow][p] = val;
      } else {
        seg[pRow][p] = cal(seg[pRow << 1][p], seg[pRow<<1 | 1][p]);
      }
    } else {
      int m = (b + e) >> 1;
      if (y <= m) 
        updateCol(pRow, x, y, val, r1, r2, b, m, p<<1);
      else
        updateCol(pRow, x, y, val, r1, r2, m+1, e, p<<1 | 1);
      seg[pRow][p] = cal(seg[pRow][p<<1], seg[pRow][p<<1 | 1]);
    }
  }

  void updateRow(int x, int y, int val, int b, int e, int p) {
    if (b == e) {
      updateCol(p, x, y, val, b, e, 1, n, 1);
    } else {
      int m = (b + e) >> 1;
      if (x <= m) {
       updateRow(x, y, val, b, m, p << 1);
      } else {
       updateRow(x, y, val, m+1, e, p << 1|1);
      }
      updateCol(p, x, y, val, b, e, 1, n, 1);
    }
  }

  void update(int x, int y, int val) {
    updateRow(x, y, val, 1, n, 1);
  }
};

int min(int x, int y) { return x < y ? x : y; }
int max(int x, int y) { return x > y ? x : y; }

int main() {
  // freopen("input.txt", "r", stdin);
  int n; scanf("%d", &n);
  
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      scanf("%d", &a[i][j]);
  
  SMT s_min(n,  1e9, min), s_max(n, -1e9, max);

  int q; scanf(" %d", &q);
  while (q--) {
    char op; scanf(" %c", &op);
    if (op == 'c') {
      int r, c, v; scanf("%d%d%d", &r, &c, &v);
      s_min.update(r, c, v), s_max.update(r, c, v);
    } else {
      int r1, c1, r2, c2; scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
      printf("%d %d\n", s_max.query(r1, c1, r2, c2), s_min.query(r1, c1, r2, c2));
    }
  }
  return 0;
}