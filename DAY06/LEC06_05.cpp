/**
 *    author:  ChimengSoso
 *    created: Thu Jan 24 2019
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    map<tuple<int,int,int,int,int>, int> fq;
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a[5]; scanf("%d%d%d%d%d", a, a+1, a+2, a+3, a+4);
        sort(a, a+5);
        fq[make_tuple(a[0], a[1], a[2], a[3], a[4])]++;
    }
    int mx = 0;
    for (auto mem: fq)
        mx = max(mx, mem.second);

    int rlt = 0;
    for (auto mem : fq) {
        if (mem.second == mx)
            rlt += mem.second;
    }

    cout <<rlt;
    return 0;
}
