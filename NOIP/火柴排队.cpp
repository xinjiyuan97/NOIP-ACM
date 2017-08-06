//
//  main.cpp
//  火柴排队
//
//  Created by 辛济远 on 2017/8/5.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;


struct arr {
  int x, index;
};

arr s1[100002], s2[100002];
int bit[100002];

int lowbit(int x) {
  return x & -x;
}

void add(int x, int n) {
  while (x <= n) {
    bit[x] += 1;
    x += lowbit(x);
  }
}

int query(int x) {
  int res = 0;
  while (x) {
    res += bit[x];
    x -= lowbit(x);
  }
  return res;
}

bool cmp1(const arr &x, const arr &y) {
  return x.x < y.x;
}

bool cmp2(const arr &x, const arr &y) {
  return x.index < y.index;
}

int main(int argc, const char * argv[]) {
  int n;
  int ans;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s1[i].x;
    s1[i].index = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> s2[i].x;
    s2[i].index = i;
  }
  
  sort(s1, s1 + n, cmp1);
  sort(s2, s2 + n, cmp1);

  for (int i = 0; i < n; i++)
    s1[i].x = i;
  
  sort(s1, s1 + n, cmp2);
  
//  for (int i = 0; i < n; i++)
//    cout << s2[i].x << " ";
//  cout << endl;
//  for (int i = 0; i < n; i++)
//    cout << s1[i].x << " ";
//  cout << endl;
//  for (int i = 0; i < n; i++)
//    cout << s1[i].index << " ";
  
  
//  for (int i = 0; i < n; i++)
//    s2[s1[i].x].x = i;
  for (int i = 0; i < n; i++)
    s2[s1[i].x].x = n - i;
  
  sort(s2, s2 + n, cmp2);
  
  ans = 0;
  for (int i = 0; i < n; i++) {
    ans += query(s2[i].x);
    add(s2[i].x, n);
    ans %= 99999997;
  }
  cout << ans << endl;
//  cout << endl;
//  for (int i = 0; i < n; i++)
//    cout << s2[i].x << " ";
  
  return 0;
}
