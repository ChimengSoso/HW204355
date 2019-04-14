/**
 *    author:  ChimengSoso
 *    created: Thu Feb 21 2019
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    int n; scanf("%d", &n);

    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int m; scanf("%d", &m);

    vector<int> t(m+1);
    t[0] = 0;
    for (int i = 1; i <= m; ++i) {
        t[i] = -1e9;
        for (int j = 0; j <= min(n, i); ++j) {
            t[i] = max(t[i], t[i-j] + a[j]);
        }
    }
    printf("%d", t[m]);
    return 0;
}
