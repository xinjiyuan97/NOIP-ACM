//
//  main.cpp
//  1042
//
//  Created by 辛济远 on 2017/3/12.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

class bigNum {
public:
  int s[10000];
  bigNum() {
    s[0] = 1;
    s[1] = 1;
  }
  bigNum operator* (int x){
    bigNum ret;
    ret.s[0] = s[0];
    int t = 0;
    for (int i = 1; i <= s[0]; i++) {
      ret.s[i] = s[i] * x + t;
      t = ret.s[i] / 10000;
      ret.s[i] %= 10000;
    }
    while (t) {
      ret.s[0]++;
      ret.s[ret.s[0]] = t % 10000;
      t /= 10000;
    }
    return ret;
  }
};

ostream& operator << (ostream &out, const bigNum &x) {
  out << x.s[x.s[0]];
  for (int i = x.s[0] - 1; i >= 1; i--)
    out << setw(4) << setfill('0') << x.s[i];
  return out;
}

int main(int argc, const char * argv[]) {
  int N;
  while (cin >> N) {
    bigNum ans;
    for (int i = 1; i <= N; i++)
      ans = ans * i;
    cout << ans << endl;
  }
  return 0;
}
