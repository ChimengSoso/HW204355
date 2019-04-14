/**
 *    author:  ChimengSoso 
 *    created: 2019-02-02 18:12:39 
**/

#include <bits/stdc++.h>
using namespace std;
long long qs[1000005];
int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        qs[i] = qs[i-1] + x;
    }
    while (m--) {
        int l, r; scanf("%d%d", &l, &r);
        printf("%lld\n", qs[r+1] - qs[l]);
    }
    return 0;
}