/**
 *    author:  ChimengSoso
 *    created: Thu Feb 21 2019
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    int n; scanf("%d", &n);
    int mx_len = -2e9, mx = -2e9, lst_idx = 0;
    int len = 0, sm = 0;
    for (int i = 1; i < n; ++i) {
        int a; scanf("%d", &a);
        if (a > sm + a) {
            sm = a;
            len = 1;
        } else {
            sm = sm + a;
            len += 1;
        }
        if (sm > mx || (sm == mx && len > mx_len)) {
            mx = sm;
            lst_idx = i;
            mx_len = len;
        }
    }
    if (mx >= 0)
        printf("%d %d", lst_idx-mx_len+1, lst_idx+1);
    else 
        printf("no");
    return 0;
}