/**
 *    author:  ChimengSoso
 *    created: Mon Apr 29 2019 23:21:35
 *    file:    LEC25_02.cpp
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  int t; scanf("%d", &t);
  while (t--) {
    int ax1, ax2, ax3, ax4;
    scanf("%d%d%d%d", &ax1, &ax2, &ax3, &ax4);

    int bx1, bx2, bx3, bx4;
    scanf("%d%d%d%d", &bx1, &bx2, &bx3, &bx4);
    
    /* #### insight of variable ####
            . - - - - - -. (x3, x4)
            |            |
            |            |
            . - - - - - -.
        (x1, x2)
    */
    
    if (ax1 <= bx3 && bx1 <= ax3 && ax2 <= bx3 && bx2 <= ax3) {
      printf("%d %d %d %d\n", max(ax1, bx1), max(ax2, bx2),
                              min(ax3, bx3), min(ax4, bx4));
    } else {
      printf("No Overlap\n");
    }
  }
  return 0;
}