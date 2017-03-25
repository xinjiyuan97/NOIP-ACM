//
//  main.cpp
//  1312
//
//  Created by 辛济远 on 2017/3/11.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int W, H;

char s[25][25];
queue <pair<int , int> > Q;

int bfs() {
  int ans;
  int x, y;
  while (!Q.empty()) {
    x = Q.front().first;
    y = Q.front().second;
    if (x < 0 || x >= H || y < 0 || y >= W)
      continue;
    if (s[x][y] != '.')
      continue;
    s[x][y] = '#';
    ans++;
    Q.push(make_pair(x + 1 , y));
    Q.push(make_pair(x - 1 , y));
    Q.push(make_pair(x , y + 1));
    Q.push(make_pair(x , y - 1));
  }
  return ans;
}

int main(int argc, const char * argv[]) {
  int x, y;
  while (scanf("%d %d", &W, &H) != EOF && (W != 0 || H != 0)) {
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
    Q.push(make_pair(x , y));
    printf("%d\n" , bfs());
  }
  return 0;
}
