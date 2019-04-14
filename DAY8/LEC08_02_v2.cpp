/**
 *    author:  ChimengSoso 
 *    created: 2019-02-02 18:12:16 
**/

#include <bits/stdc++.h>
using namespace std;
int a[5005], qs[5005],t[5005][13];
int main() {
    // freopen("input.txt", "r", stdin);
    int n, m; cin >> n >> m;

    int len = (int)sqrt(n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        t[i][0] = a[i];
    }

    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        qs[i] = qs[i-1] + x;
    }

    for (int i = 1; 1 << i <= n; ++i)
        for (int j = 1; j + (1<<i) - 1 <= n; ++j) 
            t[j][i] = max(t[j][i-1], t[j+(1<<(i-1))][i-1]);
    
    while (m--) {
        int l, r; scanf("%d%d", &l, &r);
        int p = (int)log2(r++ - l++ +1);
        printf("%d %d\n", max(t[l][p], t[r-(1<<p)+1][p]), qs[r] - qs[l-1]);
    }
    return 0;
}