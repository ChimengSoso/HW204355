/**
 *    author:  ChimengSoso
 *    created: Thu Jan 24 2019
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    char s[55]; scanf("%s", s);
    int n = strlen(s);
    
    int i = n-1, j = n-1;
    while (i > 0 and s[i-1] >= s[i]) --i;
    
    if (i <= 0) return printf("No Successor"), 0;
    
    while (s[j] <= s[i-1]) --j;
    swap(s[i-1], s[j]);
    reverse(s+i, s+n);
    
    printf("%s", s);
    return 0;
}