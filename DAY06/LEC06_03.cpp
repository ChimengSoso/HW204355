/**
 *    author:  ChimengSoso
 *    created: Thu Jan 24 2019
**/

#include <bits/stdc++.h>
using namespace std;

string strip(string s) {
    string rlt = "";
    for (int i = 0; i < s.length(); ++i)
        if (isalpha(s[i]))
            rlt += tolower(s[i]);
    return rlt;
}

int main() {
    //freopen("input.txt", "r", stdin);
    set<string> dict;
    string s;
    while (getline(cin, s)) {
        for (int i = 0; i < s.length(); ++i) {
            if (!isalpha(s[i]))
                s[i] = ' ';
        }
        istringstream iss(s);
        string word;
        while (iss >> word)
            dict.insert(strip(word));
    }
    for (string mem : dict)
        if (mem.size() > 0)
            cout << mem << '\n';
    return 0;
}
