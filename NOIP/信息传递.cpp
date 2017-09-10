//
//  main.cpp
//  信息传递
//
//  Created by 辛济远 on 2017/9/9.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

queue <int> Q;

int s[200002];
int s1[200002];
int l[200002];
void wash(int n) {
  for (int i = 1; i <= n; i++)
    if (!s1[i])
      Q.push(i);
  while(!Q.empty()) {
    int f = Q.front();
    Q.pop();
    s1[s[f]]--;
    
    if(!s1[s[f]])
      Q.push(s[f]);
    s[f] = 0;
  }
}

int check(int n) {
  int res = INT_MAX;
  for (int i = 1; i <= n; i++)
    if (s[i] && !(l[i])) {
      Q.push(i);
      l[i] = 1;
      while (!Q.empty()) {
        int f = Q.front();
        Q.pop();
        if (l[s[f]]) {
          if (res > l[f] + 1 - l[s[f]])
            res = l[f] + 1 - l[s[f]];
        }
        else {
          Q.push(s[f]);
          l[s[f]] = l[f] + 1;
        }
      }
    }
  
  if (res > 200000)
    res = 0;
  return res;
}

int main(int argc, const char * argv[]) {
  int n, m;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s1[s[i]]++;
  }
  wash(n);
  cout << check(n) << endl;
  
  return 0;
}
