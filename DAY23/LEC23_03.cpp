/**
 *    author:  ChimengSoso
 *    created: Mon Apr 15 2019 0:38:12
 *    file:    LEC23_03.cpp
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  string in, sub;
  getline(cin, in);
  cin >> sub;

  vector<int> rlt;
  int pos = in.find(sub);
  while (pos != string::npos) {
    rlt.push_back(pos);
    pos = in.find(sub, pos+1);
  }
  
  if (rlt.size() == 0)
    return printf("NOT FOUND"), 0;
  
  for (int ans : rlt) 
    printf("%d\n", ans);
  return 0;
}