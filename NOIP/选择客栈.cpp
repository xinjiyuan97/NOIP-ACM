//
//  main.cpp
//  选择客栈
//
//  Created by 辛济远 on 2017/8/4.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int s[50][200000];
//int val[200000], c[200000];
int c[50];
int cache[50];
int main(int argc, const char * argv[]) {
  int n, k, p;
  int col, pri;
  int ans = 0;
//  memset(val, 0, sizeof(val));
//  memset(s, 0, sizeof(s));
  cin >> n >> k >> p;
  for (int i = 0; i < n; i++) {
    cin >> col >> pri;
    c[col]++;
    if (pri <= p) {
      for (int j = 0; j < k; j++) {
        cache[j] += c[j];
        c[j] = 0;
      }
      ans += cache[col] - 1;
    }
    else
      ans += cache[col];
  }
  cout << ans << endl;
//    for (int j = 0; j < k; j++)
//      if (j == c[i])
//        s[j][i] = s[j][i - 1] + 1;
//      else
//        s[j][i] = s[j][i - 1];
//  }
//  for (int i = n - 1; i >= 0; i--)
//    if (val[i] <= p)
//      ans += s[c[i]][i] - 1;
//  cout << ans << endl;
  return 0;
}
