//
//  main.cpp
//  1321
//
//  Created by 辛济远 on 2017/5/13.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>

using namespace std;

int ans;
char s[10][10];
bool p[10];
int n, k;


void func(int x, int c) {
  if (c == k) {
    ans++;
    return;
  }
  if (x >= n)
    return;
  for (int i = 0; i < n; i++)
    if (s[x][i] == '#' && !p[i]) {
      s[x][i] = '*';
      p[i] = true;
      func(x + 1 , c + 1);
      s[x][i] = '#';
      p[i] = false;
    }
  func(x + 1 , c);
  return;
}


int main(int argc, const char * argv[]) {
  while (scanf("%d %d", &n, &k) != EOF && (n != -1 || k != -1)) {
    ans = 0;
    memset(p, false, sizeof(p));
    for (int i = 0; i < n; i++)
      scanf("%s", s[i]);
    //for (int i = 0; i < n; i++)
      func(0, 0);
    printf("%d\n", ans);
  }
  return 0;
}
