//
//  main.cpp
//  HighPrecision(char)
//
//  Created by 辛济远 on 2017/4/9.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
  char s1[1000], s2[1000], s3[1000];
  int l1, l2, l;
  int t;
  cin >> s1 >> s2;
  l1 = strlen(s1);
  l2 = strlen(s2);
  
  for (int i = 0; i < l1 / 2; i++)
    swap(s1[i], s1[l1 - i - 1]);
  for (int i = 0; i < l2 / 2; i++)
    swap(s2[i], s2[l2 - i - 1]);
  //cout << s1 << " " << s2 << endl;
  
  l = max(l1 , l2);
  for (int i = l1; i < l; i++)
    s1[i] = '0';
  for (int i = l2; i < l; i++)
    s2[i] = '0';
  
  t = 0;
  for (int i = 0; i < l; i++) {
    int add = s1[i] - '0' + s2[i] - '0' + t;
    t = add / 10;
    s3[i] = add % 10 + '0';
  }
  if (t)
    s3[l++] = t + '0';
  s3[l] = '\0';
  
  for (int i = 0; i < l / 2; i++)
    swap(s3[i] , s3[l - i - 1]);
  cout << s3 << endl;
  return 0;
}
