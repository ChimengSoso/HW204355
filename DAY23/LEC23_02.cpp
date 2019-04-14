/**
 *    author:  ChimengSoso
 *    created: Sun Apr 14 2019 21:32:42
 *    file:    LEC23_02.cpp
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  string in; getline(cin, in);
  int cntNmb = 0, cntApb = 0, cntCsn = 0;
  for (char ch : in) {
    char c = towlower(ch);
    if (!isalnum(c)) continue;
    if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
      cntApb++;
    else if (isdigit(c))
      cntNmb++;
    else
      cntCsn++;
  }
  printf("%d %d %d", cntNmb, cntApb, cntCsn);
  return 0;
}