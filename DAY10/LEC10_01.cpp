/**
 *    author:  ChimengSoso 
 *    created: 2019-02-10 11:02:13 
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20;

char A[N], lazy[N << 1];
int n, seg[N << 1];

int input() {  // return length of string input
  char c[205] = {};
  int m, idx = 0, n; scanf("%d", &m);
  while (m--) {
    scanf("%d %s", &n, c);
    while (n--) {
      for (int i = 0; c[i]; ++i)
        A[idx++] = c[i];
    }
  }
  A[idx] = 0; // null character
  return idx;
}

void build(int p = 1, int b = 0, int e = n - 1) {
  if (b == e) {
    seg[p] = A[b] - '0';
  } else {
    int m = (b + e) / 2;
    build(p << 1, b, m);
    build(p << 1 | 1, m + 1, e);
    seg[p] = seg[p << 1] + seg[p << 1 | 1];
  }
}

void change(char &pos, char val) {
  if (val == 'I') {
    if (!pos)
      pos = 'I';
    else if (pos == 'I')
      pos = 0;
    else if (pos == 'E')
      pos = 'F';
    else
      pos = 'E';
  } else {
    pos = val;
  }
}

void push(int p, int b, int e) {
  if (!lazy[p])
    return;
  if (lazy[p] == 'E')
    seg[p] = 0;
  else if (lazy[p] == 'F')
    seg[p] = e - b + 1;
  else
    seg[p] = (e - b + 1) - seg[p];
  if (b != e) {
    change(lazy[p << 1], lazy[p]);
    change(lazy[p << 1 | 1], lazy[p]);
  }
  lazy[p] = 0;
}

int query(int l, int r, int p = 1, int b = 0, int e = n - 1) {
  push(p, b, e);
  if (b > r || e < l)
    return 0;
  if (b >= l && e <= r)
    return seg[p];
  int m = (b + e) / 2;
  return query(l, r, p << 1, b, m) + query(l, r, p << 1 | 1, m + 1, e);
}

void update(int l, int r, char cho, int p = 1, int b = 0, int e = n - 1) {
  push(p, b, e);
  if (b > r || e < l)
    return;
  if (b >= l && e <= r) {
    change(lazy[p], cho);
    push(p, b, e);
    return;
  }
  int m = (b + e) / 2;
  update(l, r, cho, p << 1, b, m);
  update(l, r, cho, p << 1 | 1, m + 1, e);
  seg[p] = seg[p << 1] + seg[p << 1 | 1];
}

int main() {
  freopen("input.txt", "r", stdin);
  n = input(); // function input will return length of string input
  int q;
  scanf("%d", &q);
  build();
  while (q--) {
    char option;
    int a, b;
    scanf(" %c%d%d", &option, &a, &b);
    if (option == 'S') {
      printf("%d\n", query(a, b));
    } else {
      update(a, b, option);
    }
  }
  return 0;
}