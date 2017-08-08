//
//  main.cpp
//  聪明的质监员
//
//  Created by 辛济远 on 2017/8/7.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>
#include <climits>
using namespace std;


int l, r, mid;
int w[200002], v[200002];
long long y[200002];
int L[200002], R[200002];
long long sum1[200002], sum2[200002];

long long _abs(long long x) {
  if (x < 0)
    return -x;
  return x;
}

long long cal(int W, int n, int m) {
  long long res = 0;
  sum2[0] = sum1[0] = 0;
  for (int i = 1; i <= n; i++)
    if (w[i] >= W) {
      sum2[i] = sum2[i - 1] + 1;
      sum1[i] = sum1[i - 1] + v[i];
    }
    else {
      sum2[i] = sum2[i - 1];
      sum1[i] = sum1[i - 1];
    }
//  
//  for (int i = 1; i <= n; i++)
//    cout << sum1[i] << " ";
//  cout << endl;
//  for (int i = 1; i <= n; i++)
//    cout << sum2[i] << " ";
//  cout << endl;
//
  for (int i = 0; i < m; i++)
    res += (sum2[R[i]] - sum2[L[i] - 1]) * (sum1[R[i]] - sum1[L[i] - 1]);
  return res;
}


int main(int argc, const char * argv[]) {
  long long n, m, S, Y;
  long long res;
  cin >> n >> m >> S;
  cin >> w[1] >> v[1];
  l = r = w[1];
  for (int i = 2; i <= n; i++) {
    cin >> w[i] >> v[i];
    if (w[i] < l)
      l = w[i];
    if (w[i] > r)
      r = w[i];
  }
  //cout << l << " " << r << endl;
  for (int i = 0; i < m; i++)
    cin >> L[i] >> R[i];
  res = _abs(cal(l, n, m) - S);
  while (r >= l) {
    mid = (l + r) / 2;
    Y = cal(mid, n, m);
    res = min(res, _abs(Y - S));
    if (Y < S)
      r = mid - 1;
    else
      l = mid + 1;
  }
  cout << res << endl;
  return 0;
}
