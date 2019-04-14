#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}
int main () {
    ll n;
    cin >> n;
    ll G = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            G += gcd(i, j);
        }
    }
    cout << G;
    return 0;
}
