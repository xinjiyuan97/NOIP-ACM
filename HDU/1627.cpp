//
//  main.cpp
//  1627
//
//  Created by 辛济远 on 2017/3/13.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
int n, L, D;
int unfind;
char s[100];


void OUTPUT(int x) {
  unfind = false;
  int t = 0;
  putchar(s[0]);
  for (int i = 1; i < x; i++) {
    if (!(i % 4)) {
      t++;
      if (t == 16) {
        putchar('\n');
        t = 0;
      }
      else
        putchar(' ');
    }
    putchar(s[i]);
  }
  putchar('\n');
  printf("%d\n" , x);
}

bool check(int x) {
  bool ret;
  for (int i = x - 1; i >= x / 2; i--)
    if (s[i] == s[x]) {
      ret = false;
      for (int j = 0; j < x - i; j++)
        if (s[x - j] != s[i - j]) {
          ret = true;
          break;
        }
      if (!ret)
        return false;
    }
  return true;
}

void DFS(int x) {
  if (D == n) {
    OUTPUT(x);
    return;
  }
  for (int i = 0; i < L && unfind; i++) {
    s[x] = 'A' + i;
    if(check(x)) {
      //printf("%d %s\n", D, s);
      D++;
      
      DFS(x + 1);
    }
    else
      s[x] = 0;
  }
}

int main(int argc, const char * argv[]) {
  while (scanf("%d %d", &n, &L) != 0 && (n != 0 || L != 0)) {
    memset(s , 0 , sizeof(s));
    unfind = true;
    D = 0;
    DFS(0);
  }
  return 0;
}
