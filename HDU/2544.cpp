//
//  main.cpp
//  2544
//
//  Created by 辛济远 on 2017/5/19.
//  Copyright © 2017年 辛济远. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector <pair<int, int> > V[101];

int main(int argc, const char * argv[]) {
  int n, m;
  int a, b, c;
  bool node[101];
  int d[101];
  while (scanf("%d %d", &n, &m) != EOF && (n != 0 || m != 0)) {
    memset(node, 0, sizeof(node));
    memset(d , 127 , sizeof(d));
    for (int i = 1; i <= n; i++)
      V[i].clear();
    for (int i = 1; i <= m; i++) {
      scanf("%d %d %d", &a, &b, &c);
      V[a].push_back(make_pair(b, c));
      V[b].push_back(make_pair(a, c));
    }
    d[1] =  0;
    for (int i = 1; i <= n; i++) {
      int x = 1, length = INT_MAX;
      for (int j = 1; j <= n; j++)
        if (length > d[j] && !node[j])
          length = d[x = j];
      node[x] = 1;
      for (int j = 0; j < V[x].size(); j++)
        if (d[V[x][j].first] > d[x] + V[x][j].second)
          d[V[x][j].first] = d[x] + V[x][j].second;
    }
    printf("%d\n", d[n]);
  }
  return 0;
}
