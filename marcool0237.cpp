//
//  main.cpp
//  0237
//
//  Created by 辛济远 on 2017/3/19.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

char s[10][10];
bool ans;

bool check(int x, int y) {
  int Q[10];
  memset(Q , 0 , sizeof(Q));
  for (int i = 0; i < 9; i++)
    if (s[x][i] != '?') {
      if (Q[s[x][i] - '0'])
        return false;
      else
        Q[s[x][i] - '0'] = true;
    }
  memset(Q , 0 , sizeof(Q));
  for (int i = 0; i < 9; i++)
    if (s[i][y] != '?') {
      if (Q[s[i][y] - '0'])
        return false;
      else
        Q[s[i][y] - '0'] = true;
    }
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) {
      memset(Q , 0 , sizeof(Q));
      for (int x1 = (i - 1) * 3; x1 <= i * 3; x1++)
        for (int y1 = (j - 1) * 3; y1 <= j * 3; y1++)
          if (s[x1][y1] != '?') {
            if (Q[s[x1][y1] - '0'])
              return false;
            else
              Q[s[x1][y1] - '0'] = true;
          }
    }
  
  return true;
}

void OUTPUT() {
  cout << endl;
  for (int i = 0; i < 9; i++) {
    cout << s[i][0];
    for (int j = 1; j < 9; j++)
      cout << " " << s[i][j];
    cout << endl;
  }
}

void work() {
  int x, y;
  x = y = -1;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      if (s[i][j] == '?') {
        x = i;
        y = j;
        i = 10;
        j = 10;
      }
  if (x < 0 && y < 0) {
    ans = true;
    OUTPUT();
    return;
  }
  for (int i = 1; i <= 9; i++) {
    s[x][y] = i + '0';
    if (check(x , y) == true) {
      OUTPUT();
      work();
      
    }
    if (ans)
      return;
    s[x][y] = '?';
  }
  
}


int main(int argc, const char * argv[]) {
  ans = false;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      cin >> s[i][j];
  work();
  return 0;
}
