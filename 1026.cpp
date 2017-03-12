//
//  main.cpp
//  1026
//
//  Created by 辛济远 on 2017/2/21.
//  Copyright © 2017年 辛济远. All rights reserved.
//
#include <stdio.h>
#include <climits>
#include <queue>
using namespace std;

struct node {
  int nextX, nextY;
  int T;
};

int N, M;
node map[102][102];
char s[102][102];
queue <pair<int , int> > Q;
/*
 void init() {
 front = tail = 0;
 return;
 }
 
 void push(pair <int , int> x) {
 Q[tail++] = x;
 return;
 }
 
 pair<int , int> pop() {
 return
 }
 */
void move(int a, int b, int x, int y) {
  if (a < 0 || a >= N || b < 0 || b >= M)
    return;
  if (s[a][b] == 'X')
    return;
  if (map[a][b].T > map[x][y].T + s[a][b] + 1) {
    map[a][b].nextX = x;
    map[a][b].nextY = y;
    map[a][b].T = map[x][y].T + s[a][b] + 1;
    Q.push(make_pair(a , b));
  }
}

void BFS() {
  int x, y;
  Q.push(make_pair(N - 1 , M - 1));
  map[N - 1][M - 1].T = s[N - 1][M - 1];
  map[N - 1][M - 1].nextX = -1;
  map[N - 1][M - 1].nextY = -1;
  while (!Q.empty()) {
    x = Q.front().first;
    y = Q.front().second;
    Q.pop();
    move(x - 1 , y , x , y);
    move(x + 1 , y , x , y);
    move(x , y - 1 , x , y);
    move(x , y + 1 , x , y);
  }
  return;
}

void Output() {
  int T, x, y, c;
  T = 1;
  x = y = 0;
  if (map[0][0].T < 100000) {
    printf("It takes %d seconds to reach the target position, let me show you the way.\n" , map[0][0].T);
    while (T <= map[0][0].T) {
      while (s[x][y]) {
        printf("%ds:FIGHT AT (%d,%d)\n", T, x, y);
        s[x][y]--;
        T++;
      }
      if (T <= map[0][0].T) {
        printf("%ds:(%d,%d)->(%d,%d)\n", T, x, y, map[x][y].nextX, map[x][y].nextY);
        c = x;
        x = map[x][y].nextX;
        y = map[c][y].nextY;
        T++;
      }
    }
  }
  else
    printf("God please help our poor hero.\n");
  printf("FINISH\n");
}

int main() {
  char space;
  while(scanf("%d %d\n", &N, &M) != EOF) {
    //init();
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        scanf("%c" , &s[i][j]);
        map[i][j].T = INT_MAX;
        if (s[i][j] == '.')
          s[i][j] = 0;
        if (s[i][j] <= '9' && s[i][j] > '0')
          s[i][j] -= '0';
      }
      scanf("%c", &space);
    }
    BFS();
    Output();
  }
  return 0;
}
