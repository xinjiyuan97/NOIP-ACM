//
//  main.cpp
//  HighPrecision
//
//  Created by 辛济远 on 2017/4/9.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class BigNum {
public:
  int s[1000];
  BigNum () {
    memset(s , 0 , sizeof(s));
  }
  BigNum operator + (BigNum x) {
    BigNum ans;
    int t;
    ans.s[0] = max(x.s[0] , s[0]);
    t = 0;
    for (int i = 1; i < ans.s[0]; i++) {
      ans.s[i] = x.s[i] + s[i] + t;
      t = ans.s[i] / 10000;
      ans.s[i] %= 10000;
    }
    if (t)
      ans.s[ans.s[0]++] = t;
    return ans;
  }
  BigNum operator * (BigNum x) {
    BigNum ans;
    ans.s[0] = s[0] + x.s[0];
    for (int i = 1; i < s[0]; i++)
      for (int j = 1; j < x.s[0]; j++)
        ans.s[i + j - 1] += s[i] * x.s[i];
    int t = 0;
    for (int i = 1; i <= ans.s[0]; i++) {
      ans.s[i] += t;
      t = ans.s[i] / 10000;
      ans.s[i] %= 10000;
    }
    while (t) {
      ans.s[ans.s[0]++] = t % 10000;
      t /= 10000;
    }
    return ans;
  }
};

ostream& operator <<(ostream &out, const BigNum &x) {
  out << x.s[x.s[0] - 1];
  for (int i = x.s[0] - 2; i >= 1; i--)
    out << setw(4) << setfill('0') << x.s[i];
  out << endl;
  return out;
}

istream& operator >>(istream &in, BigNum &x) {
  char s[4000];
  in >> s;
  int l = strlen(s);
  x.s[0] = 1;
  for (int i = l - 1; i >= 0; i -= 4) {
    x.s[x.s[0]] = 0;
    for (int j = 0; j < 4 && (i - j) >= 0; j++) {
      x.s[x.s[0]] *= 10;
      x.s[x.s[0]] += s[i - j] - '0';
    }
    x.s[0]++;
  }
 return in;
}

int main(int argc, const char * argv[]) {
  BigNum a, b;
  cin >> a >> b;
  cout << a + b << endl;
  return 0;
}
