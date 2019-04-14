#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    int cnt = 1;
    long long mx = n;
    while (n > 1) {
        n = n % 2 ? sqrt(n*n*n) : sqrt(n);
        cnt++;
        mx = max(mx, n);
    }
    cout << mx << ' ' << cnt;
    return 0;
}
