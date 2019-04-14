/**
 *    author:  ChimengSoso 
 *    created: 2019-02-02 18:12:16 
**/

#include <bits/stdc++.h>
using namespace std;
int qs[5005], a[5005], srt[80];
int main() {
    // freopen("input.txt", "r", stdin);
    int n, m; cin >> n >> m;
    int len = (int)sqrt(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        int idx = i / len;
        srt[idx] = max(srt[idx], a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        qs[i] = qs[i-1] + x;
    }
    while (m--) {
        int l, r; scanf("%d%d", &l, &r);
        int mx = 0, i = l;
        while (i <= r) {
            if (i % len == 0 and i + len - 1 <= r) {
                mx = max(mx, srt[i / len]);
                i += len;
            } else
                mx = max(mx, a[i++]);
        }
        printf("%d %d\n", mx, qs[r+1] - qs[l]);
    }
    return 0;
}