/*
作者:xinjiyuan97
题目:p3286 火柴排队
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int s1[100005], s2[100005];
int a[100005];

bool cmp(const int &x, const int &y) {
  return a[x] < a[y];
}

int lowbit(int x) {
  return x & (-x);
}

int main() {
  int i, m, Q, ans;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    s1[i] = i;
  }
  sort(s1 + 1 , s1 + 1 + n , cmp);
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    s2[i] = i;
  }
  sort(s2 + 1 , s2 + 1 + n , cmp);
  for (i = 1; i <= n; i++)
    a[s2[i]] = s1[i];
  //for (i = 1; i <= n; i++)
    //cout << a[i] << " " << s2[i] << endl;
  memset(s1 , 0 , sizeof(s1));
  for (i = 1, ans = 0; i <= n; i++) {
    m = a[i];
    while (m <= n) {
      s1[m]++;
      m += lowbit(m);
    }
    m = a[i];
    Q = 0;
    while (m > 0) {
      Q += s1[m];
      m -= lowbit(m);
    }
    //cout << Q << endl;
    ans += i - Q;
    ans %= 99999997;
  }
  cout << ans << endl;
  return 0;
}
