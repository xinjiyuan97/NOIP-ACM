//
//  main.cpp
//  1584
//
//  Created by 辛济远 on 2017/12/10.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>
#include <climits>

using namespace std;

int s[11];
bool mark[11];
int ans;

void dfs(int deep, int length) {
  if (length >= ans)
    return;
  if (deep == 9) {
    ans = length;
    return;
  }
  for (int i = 1; i < 10; i++)
    if (mark[i] == false) {
      mark[i] = true;
      for (int j = i + 1; j <= 10; j++) {
        if (mark[j] == false) {
          dfs(deep + 1, length + abs(s[i] - s[j]));
          break;
        }
      }
      mark[i] = false;
    }
}


int main(int argc, const char * argv[]) {
  int T, x;
  scanf("%d", &T);
  
  while (T--) {
    for (int i = 0; i < 10; i++) {
      scanf("%d", &x);
      s[x] = i;
    }
    memset(mark, 0, sizeof(mark));
    ans = INT_MAX;
    dfs(0, 0);
    printf("%d\n", ans);
  }
  return 0;
}
