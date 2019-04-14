#include <bits/stdc++.h>
using namespace std;
bool ss[1005];
int main() {
  // freopen("input.txt", "r", stdin);
  int n, p; scanf("%d%d", &n, &p);
  if (n == 0) return printf("NO"), 0;
  ss[0] = true;
  for (int i = 1; i <= p; ++i) {
    int a; scanf("%d", &a);
    for (int j = n; j >= 0; --j) {
      if (ss[j] and j + a <= n)
        ss[j+a] = true;
    }
  }
  printf("%s", ss[n] ? "YES": "NO");
  return 0;
}
