//
//  main.cpp
//  买铅笔
//
//  Created by 辛济远 on 2017/8/6.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
  int n;
  cin >> n;
  int c1, p1, c2, p2, c3, p3, P1, P2, P3;
  cin >> c1 >> p1;
  cin >> c2 >> p2;
  cin >> c3 >> p3;
  P1 = ((n / c1) + (n % c1 != 0)) * p1;
  P2 = ((n / c2) + (n % c2 != 0)) * p2;
  P3 = ((n / c3) + (n % c3 != 0)) * p3;
  P1 = min(P1, P2);
  P1 = min(P1, P3);
  cout << P1 << endl;
  return 0;
}
