/**
 *    author:  ChimengSoso
 *    created: Mon Jan 14 2019
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long sm = 0, mx = 0;
    while (n--) {
        int a;
        scanf("%d", &a);
        sm = max(1LL*a, sm+a);
        mx = max(mx, sm);
    }
    cout << mx;
    return 0;
}