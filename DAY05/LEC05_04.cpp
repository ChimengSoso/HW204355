/**
 *    author:  ChimengSoso
 *    created: Mon Jan 21 2019
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int* a = new int[s.length()];
    fill(a, a+s.length(), 1e9);
    for (char ch : s) {
         int mn_i = 0;
         int mn_diff = 1e9;
         for (int i = 0; i < s.length(); ++i) {
            int sol = a[i] - (ch - 'A');
            if (sol >= 0 and sol < mn_diff) {
                mn_diff = sol;
                mn_i = i;
            }
         }
         a[mn_i] = ch - 'A';
    }
    int rlt = 0;
    for (int i = 0; i < s.length(); ++i)
        if (a[i] != 1e9)
            rlt++;

    cout << rlt;
    return 0;
}
