//
//  main.cpp
//  跳石头
//
//  Created by 辛济远 on 2017/9/9.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>
#include <limits.h>
using namespace std;

int N, M;
int L, _max, _min;
int D[50002], Sub[50002];

int check(int x) {
  int move = 0, l;
  int res = L + 10;
  for (int i = 0; i < N; i++) {
    l = Sub[i];
    if (l < x)
      while (l < x && i < N) {
        i++;
        l += Sub[i];
        move++;
      }
    if (l > res)
      res = l;
  }
  //cout << " " << move << endl;
  if (move <= M)
    return l;
  return 0;
}

int main(int argc, const char * argv[]) {
  cin >> L >> N >> M;
  if (N < 1) {
    cout << L << endl;
    return 0;
  }
  cin >> D[0];
  _min = D[0];
  _max = D[0];
  Sub[0] = D[0];
  int res;
  for (int i = 1; i < N; i++) {
    cin >> D[i];
    Sub[i] = D[i] - D[i - 1];
    if (_max < Sub[i])
      _max = Sub[i];
    if (_min > Sub[i])
      _min = Sub[i];
  }
  int l, r, mid;
  l = _min;
  r = L;
  while (r - l > 1) {
    mid = (l + r) >> 1;
    //cout << r << " " << mid << " " << l;
    res = check(mid);
    if (res)
      l = mid;
    else
      r = mid;
  }
  cout << l << endl;
  return 0;
}
