#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main () {
    ll n;
    cin >> n;
    auto sn = [&](ll s) {
        return s*s;
    };
    ll rlt = 0;
    for (int i = 1; i <= n; ++i)
        rlt += sn(i);
    cout << rlt;
    return 0;
}
