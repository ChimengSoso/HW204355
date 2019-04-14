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
    auto i = in.find(".......");
    if (i == string::npos) { // not found '.......'
      while (in.size() > 0 && in.back() == '\r')
        in.pop_back();
      out += (out.size() == 0 ? "" : " ") + in;
    } else {
      for (int k = 0; k < i; ++k)
        out.push_back(in[k]);
      break;
    }
  }
  cout << out;
  return 0;
}