//
//  main.cpp
//  1308
//
//  Created by 辛济远 on 2017/5/10.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

map<int, int> M;
int E[100000];

int main(int argc, const char * argv[]) {
  int i = 0;
  int a, b;
  int res;
  int c, e;
  while (++i) {
    c = 0;
    e = 0;
    res = true;
    memset(E , -1 , sizeof(E));
    M.clear();
    while (scanf("%d %d", &a, &b) != EOF && (a != 0 || b != 0)) {
      if (a == -1 && b == -1)
        return 0;
      e++;
      if (M.find(a) != M.end())
        a = M[a];
      else {
        M[a] = ++c;
        a = M[a];
      }
      if (M.find(b) != M.end())
        b = M[b];
      else {
        M[b] = ++c;
        b = M[b];
      }
      if (E[b] != -1)
        res = false;
      E[b] = a;
    }
    if (res && c != 0) {
      if (e != c - 1)
        res = false;
      a = 0;
      for (int i = 1; i <= c; i++)
        if (E[i] == -1)
          a++;
      if (a != 1)
        res = false;
    }
    if (res)
      printf("Case %d is a tree.\n", i);
    else
      printf("Case %d is not a tree.\n", i);
  }
  return 0;
}
