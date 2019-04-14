/**
 *    author:  ChimengSoso
 *    created: Thu Jan 24 2019 19:33:16
 *    file:    LEC06_04.cpp
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  string s; cin >> s;
  cout << (next_permutation(s.begin(), s.end()) ? s : "No Successor");
  return 0;
}