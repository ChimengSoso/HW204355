/**
 *    author:  ChimengSoso
 *    created: Mon Jan 21 2019
**/

#include <bits/stdc++.h>
using namespace std;
int a[55];
int main() {
    int n; cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sum /= n;
    int rlt = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > sum) 
            rlt += a[i] - sum;
    }
    cout << rlt;
    return 0;
}