#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const ll mod = 1000000007;
int main () {
    ll n;
    cin >> n;
    cout << ((n%mod) * (n%mod))%mod;
    return 0;
}
