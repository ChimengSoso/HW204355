/**
 *    author:  ChimengSoso
 *    created: Mon Jan 21 2019
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; getline(cin, s);
    string cin_s;
    istringstream iss(s);
    while (iss >> cin_s) {
        reverse(cin_s.begin(), cin_s.end());
        cout << cin_s << ' ';
    }
    return 0;
}