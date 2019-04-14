/**
 *    author:  ChimengSoso
 *    created: Mon Jan 21 2019
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> out;
    auto it = out.begin();
    string s; cin >> s;
    for (auto ch : s) {
        if (ch == '[')
            it = out.begin();
        else if (ch == ']') 
            it = out.end();
        else 
            out.insert(it, ch);
    }
    for (auto mem : out)
        printf("%c", mem);
    return 0;
}