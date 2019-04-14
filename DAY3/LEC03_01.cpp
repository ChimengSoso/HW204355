/**
 *    author:  ChimengSoso
 *    created: Mon Jan 14 2019
**/

#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
    int n = 0;
    int num;
    string in; getline(cin, in);
    
    istringstream iss(in);
    while (iss >> num) {
        a[n++] = num;
    }

    int mx = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j)
            mx = max(mx, __gcd(a[i], a[j]));
    }
    cout << mx;
    return 0;
}