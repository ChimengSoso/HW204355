/**
 *    author:  ChimengSoso
 *    created: Sun Apr 14 2019 18:46:43
 *    file:    LEC23_01.cpp
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  string in, out = "";
  while (getline(cin, in)) {
    if (in.size() == 0) continue;
    auto i = in.substr(0, 7);
    if (i != ".......") { // not found '.......'
      if (in.back() == '\r') in.pop_back();
      out += (out.size() == 0 ? "" : " ") + in;
    } else break;
  }
  cout << out;
  return 0;
}