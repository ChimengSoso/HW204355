/**
 *    author:  ChimengSoso
 *    created: Mon Apr 15 2019 23:3:44
 *    file:    LEC23_04.cpp
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  string in; cin >> in;
  int n = in.size();
  for (int i = 1; i <= n/2; ++i) {
    if (n % i == 0) {
      bool found = true;
      for (int j = 0; j < n-2*i; j += i) {
        if (in.substr(j, i) != in.substr(j+i, i)) {
          found = false;
          break;
        }
      }
      if (found)
        return printf("%d\n", i), 0;
    }
  }
  printf("%d\n", n);
  return 0;
}