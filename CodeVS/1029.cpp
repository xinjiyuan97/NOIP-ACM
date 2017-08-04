//
//  main.cpp
//  1029
//
//  Created by 辛济远 on 2017/8/4.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
  char s1[30], s2[30];
  int l;
  cin >> s1 >> s2;
  l = strlen(s1);
  int ans = 0;
  for (int i = 1; i < l; i++)
    for (int j = 0; j < l - 1; j++)
      if (s1[i] == s2[j] && s1[i - 1] == s2[j + 1])
        ans++;
  cout << (1 << ans) << endl;
  return 0;
}
