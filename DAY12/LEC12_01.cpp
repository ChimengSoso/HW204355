#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  int n; scanf("%d", &n);
  assert(n > 1);
  int*a = new int[n];
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  vector<int> st;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      st.push_back(a[i]+a[j]);
    }
  }

  sort(st.begin(), st.end());
  st.resize(unique(st.begin(), st.end())-st.begin());

  int q; scanf("%d", &q);
  while (q--) {
    int x; scanf("%d", &x);

    if (x < st[0]) {
        printf("%d\n", st[0]-x);
        continue;
    } else {
        int l = st.size();
        if (x > st[l-1]) {
            printf("%d\n", x-st[l-1]);
            continue;
        }
    }

    int idx = lower_bound(st.begin(), st.end(), x) - st.begin();

    int rlt = abs(x-st[idx]);
    if (idx < st.size()) rlt = min(rlt, abs(x-st[idx+1]));
    if (idx > 0) rlt = min(rlt, abs(x-st[idx-1]));

    printf("%d\n", rlt);
  }
  delete a;
  return 0;
}
