//
//  main.cpp
//  1442
//
//  Created by 辛济远 on 2017/5/9.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int A[30003];
priority_queue<int, vector<int>, greater<int> > P;
priority_queue<int> Q;

int main(int argc, const char * argv[]) {
  int N, M;
  int q;
  int j;
  while (scanf("%d %d", &M, &N) != EOF) {
    while (!Q.empty()) Q.pop();
    while (!P.empty()) P.pop();
    for (int i = 0; i < M; i++)
      scanf("%d", &A[i]);
    j = 1;
    P.push(A[0]);
    for (int i = 0; i < N; i++) {
      scanf("%d", &q);
      for (; j < q; j++)
        if (P.empty() || A[j] > P.top()) {
          P.push(A[j]);
          Q.push(P.top());
          P.pop();
          
        }
        else {
          Q.push(A[j]);
        }
      while (Q.size() <= i) {
        Q.push(P.top());
        P.pop();
      }
      while (Q.size() > i + 1) {
        P.push(Q.top());
        Q.pop();
      }
      printf("%d\n", Q.top());
    }
  }
  return 0;
}
