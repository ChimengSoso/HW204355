/**
 *    author:  ChimengSoso
 *    created: Thu Jan 17 2019
**/

#include <bits/stdc++.h>
using namespace std;

int rt(int L, int R) {
    return L + rand()%(R-L+1);
}

int powMod(int a, int k, int n) {
    if (k == 0) return 1;
    int d = powMod(a, k/2, n);
    int x = (d*d) % n;
    if (x == 1 and d != 1 and d != n-1) return 0;
    if (k % 2 == 1) x = (x * a) % n;
    return x;
}

bool isProbablePrime(int n, int k) {
    if (n < 2) return false;
    if (n < 4) return true;
    for (int i = 1; i <= k; ++i) {
        int a = rt(2, n-2);
        int MRT = powMod(a, n-1, n);
        if (MRT != 1) return false;
    }
    return true;
}

bool isPrime(int n) {
    return isProbablePrime(n, 32); // error = 1 in 18,446,744,073,709,551,616
}

int main() {
    srand(time(0));
    int n; cin >> n;
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
    return 0;
}
