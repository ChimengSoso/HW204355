/**
 *    author:  ChimengSoso
 *    created: Thu Feb 21 2019
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    int n; scanf("%d", &n);
    vector<long long> t(n+1, 0);
    t[0] = 1;
    for (int i = 1; i <= n; ++i) {
        t[i] = t[i-1];
        if (i >= 3) t[i] += t[i-3];
        if (i >= 4) t[i] += t[i-4];
    }
    printf("%lld", t[n]);
    return 0;
}