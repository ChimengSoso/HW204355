/**
 *    author:  ChimengSoso
 *    created: Mon Feb 25 2019
**/

#include <bits/stdc++.h>
using namespace std;

int x[11], y[11], dst[11][11], mem[11][1<<11+1];

int tsp(int pos, int state, int n) {
    if (state+1 == 1 << (n+1)) return dst[pos][0];
    if (mem[pos][state]) return mem[pos][state];
    int best = 2e9;
    for (int i = 1; i <= n; ++i) {
        if (i == pos or state&(1<<i)) continue;
        int nxt_state = state|(1<<i);
        best = min(best, dst[pos][i] + tsp(i, nxt_state, n));
    }
    return mem[pos][state] = best;
}

int main() {
    // freopen("input.txt", "r", stdin);

    int xsz, ysz, xstart, ystart, n;
    scanf("%d%d%d%d%d", &xsz, &ysz, &x[0], &y[0], &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &x[i], &y[i]);

    // make graph
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            dst[i][j] = abs(x[i]-x[j])+abs(y[i]-y[j]);

    printf("%d", tsp(0, 1, n)); // start from node# 0 and go! PS. state is ...00001
    return 0;
}
