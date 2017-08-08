//
//  main.cpp
//  回文日期
//
//  Created by 辛济远 on 2017/8/6.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>

using namespace std;

int check(int y, int m, int d) {
  int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if ((y % 100 != 0 && y % 4 == 0) || y % 400 == 0)
    day[2] = 29;
  if (m <= 12)
    if (d <= day[m])
      //cout << y << endl;
      return 1;
  return 0;
}

int main(int argc, const char * argv[]) {
  int ans;
  int n, m;
  int y1, m1, d1, y2, m2, d2;
  int mir1, mir2;
  cin >> n >> m;
  y1 = n / 10000;
  y2 = m / 10000;
  m1 = n / 100 % 100;
  m2 = m / 100 % 100;
  d1 = n % 100;
  d2 = m % 100;
  mir1 = (y1 % 10) * 10 + y1 / 10 % 10;
  mir2 = (y1 / 100 % 10) * 10 + y1 / 1000;
  
  ans = 0;
  if (mir1 >= m1 && mir2 >= d1)
    ans += check(y1, mir1, mir2);
  
  for (int i = y1 + 1; i < y2; i++) {
    mir1 = (i % 10) * 10 + i / 10 % 10;
    mir2 = (i / 100 % 10) * 10 + i / 1000;
    ans += check(i, mir1, mir2);
  }
  if (y2 > y1) {
  mir1 = (y2 % 10) * 10 + y2 / 10 % 10;
  mir2 = (y2 / 100 % 10) * 10 + y2 / 1000;
  
  if (mir1 <= m2 && mir2 <= d2)
    ans += check(y1, mir1, mir2);
  }
  cout << ans << endl;
  return 0;
}
