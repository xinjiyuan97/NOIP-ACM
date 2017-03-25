//
//  main.cpp
//  1213
//
//  Created by 辛济远 on 2017/3/19.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int T;
int father[1002];

int find(int x) {
  if (father[x] == -1)
    return x;
  return father[x] = find(father[x]);
}

void add(int x, int y) {
  father[find(x)] = y;
}

int main(int argc, const char * argv[]) {
  scanf("%d" , &T);
  int a, b;
  int ans;
  while (T--) {
    ans = 0;
    scanf("%d %d", &N, &M);
    memset(father , -1 , sizeof(father));
    for (int i = 1; i <= M; i++) {
      scanf("%d %d", &a, &b);
      if (find(a) != find(b))
        add(a , b);
    }
    for (int i = 1; i <= N; i++)
      if (father[i] == -1)
        ans++;
    printf("%d\n", ans);
  }
  return 0;
}
