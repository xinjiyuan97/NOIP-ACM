//
//  main.cpp
//  1010
//
//  Created by 辛济远 on 2017/3/12.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>

using namespace std;

int N, M, T;
char s[10][10];
int Sx, Sy, Dx, Dy;
bool finish;

void dfs(int x, int y, int t) {
  if (x < 0 || x >= N || y < 0 || y >= M)
    return;
  int nT = T - abs(Dx - x) - (Dy - y) - t;
  if (s[x][y] == 'X' || nT < 0 || nT % 2 == 1)
    return;
  if (finish)
    return;
  if (s[x][y] == 'D') {
    if (t == T) {
      finish = true;
      return;
    }
    else
      return;
  }
  char c;
  c = s[x][y];
  s[x][y] = 'X';
  /*
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      putchar(s[i][j]);
    putchar('\n');
  }
  getchar();
  */
  dfs(x + 1 , y , t + 1);
  dfs(x - 1 , y , t + 1);
  dfs(x , y + 1 , t + 1);
  dfs(x , y - 1 , t + 1);
  s[x][y] = c;
  return;
}

int main(int argc, const char * argv[]) {
  while (scanf("%d %d %d", &N, &M, & T) != EOF && (N != 0 || M != 0 || T != 0)) {
    getchar();
    finish = false;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        s[i][j] = getchar();
        if (s[i][j] == 'S') {
          Sx = i;
          Sy = j;
        }
        if (s[i][j] == 'D') {
          Dx = i;
          Dy = j;
        }
      }
      getchar();
    }
    dfs(Sx , Sy , 0);
    if (finish)
      printf("YES\n");
    else
      printf("NO\n");
    
  }
  return 0;
}
