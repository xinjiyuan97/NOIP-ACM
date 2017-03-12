//
//  main.cpp
//  1312
//
//  Created by 辛济远 on 2017/3/11.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>

using namespace std;

int W, H;
int ans;
char s[25][25];


void dfs(int x, int y) {
  if (x < 0 || x >= H || y < 0 || y >= W)
    return;
  if (s[x][y] != '.')
    return;
  s[x][y] = '#';
  ans++;
  dfs(x + 1 , y);
  dfs(x - 1 , y);
  dfs(x , y + 1);
  dfs(x , y - 1);
  return;
}

int main(int argc, const char * argv[]) {
  int x, y;
  while (scanf("%d %d", &W, &H) != EOF && (W != 0 || H != 0)) {
    ans = 0;
    getchar();
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        s[i][j] = getchar();
        if (s[i][j] == '@') {
          x = i;
          y = j;
        }
      }
      getchar();
    }
    /*
    for (int i = 0; i < H; i++) {
      printf("\n");
      for (int j = 0; j < W; j++)
        printf("%c", s[i][j]);
    }
     */
    s[x][y] = '.';
    dfs(x , y);
    printf("%d\n" , ans);
  }
  return 0;
}
