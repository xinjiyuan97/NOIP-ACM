//
//  main.cpp
//  借教室
//
//  Created by 辛济远 on 2017/8/7.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>

using namespace std;


int last;
int r[1000002];
int d[1000002], s[1000002], t[1000002];
int S[1000002], E[1000002];

bool check(int n, int mid) {
  int use = 0;
  if (mid > last)
    for (int i = last + 1; i <= mid; i++) {
      S[s[i]] += d[i];
      E[t[i]] -= d[i];
    }
  else
    for (int i = last; i > mid; i--) {
      S[s[i]] -= d[i];
      E[t[i]] += d[i];
    }

  
  
  
//  for (int i = 1; i <= n; i++)
//    cout << S[i] << " ";
//  cout << endl;
//  for (int i = 1; i <= n; i++)
//    cout << E[i] << " ";
//  cout << endl;
  
  last = mid;
  
  for (int i = 1; i <= n; i++) {
    use += S[i];
    if (use > r[i])
      return false;
    use += E[i];
  }
  return true;
}

int main(int argc, const char * argv[]) {
  int n, m;
  int L, R;
  cin >> n >> m;
  
  for (int i = 1; i <= n; i++)
    cin >> r[i];
  for (int i = 1; i <= m; i++)
    cin >> d[i] >> s[i] >> t[i];
  L = 0, R = m;
  last = 0;
  if (check(n, m))
    cout << 0 << endl;
  else {
    while (R - L > 1) {
      int mid = (L + R) >> 1;
      if(check(n, mid))
        L = mid;
      else
        R = mid;
    }
    cout << -1 << endl << R << endl;
  }
  return 0;
}
