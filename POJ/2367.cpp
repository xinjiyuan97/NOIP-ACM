//
//  main.cpp
//  2367
//
//  Created by 辛济远 on 2017/5/13.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
  int n, m;
  int s[103];
  vector<int> V[103];
  queue<int> Q;
  while (scanf("%d" , &n) != EOF) {
    memset(s , 0 , sizeof(s));
    for (int i = 0; i < 100; i++)
      V[i].clear();
    while (!Q.empty())
      Q.pop();
    for (int i = 1; i <= n; i++)
      while (scanf("%d", &m) && m) {
        s[m]++;
        V[i].push_back(m);
      }
    for (int i = 1; i <= n; i++)
      if (!s[i]) {
        Q.push(i);
        s[i]--;
      }
    int f = Q.front();
    printf("%d", f);
    do {
      Q.pop();
      for (int i = 0; i < V[f].size(); i++)
        s[V[f][i]]--;
      for (int i = 1; i <= n; i++)
        if (!s[i]) {
          Q.push(i);
          s[i]--;
        }
      if (!Q.empty()) {
        f = Q.front();
        printf(" %d", f);
      }
    } while (!Q.empty());
    printf("\n");
  }
  return 0;
}
