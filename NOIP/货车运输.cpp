//
//  main.cpp
//  P1967
//
//  Created by 辛济远 on 2018/2/15.
//  Copyright © 2018年 辛济远. All rights reserved.
//

#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;

struct edge {
  int x, y, z;
};
struct branch {
  int y, z;
};

int n, m;
int lg[10005];
edge s[50005];
int unionFind[10005];
int f[10005][25];
int w[10005][25];
int dep[10005];
branch maxWeightTree[10005];
vector <pair<int, int> > maxWeightTreeEdges[10005];

int min(const int &x, const int &y) { return x < y ? x : y; }
bool cmp(const edge &x, const edge &y) { return x.z > y.z; }

// TODO: union find set
void initUnion() { memset(unionFind, -1, sizeof(unionFind)); }

int findSet(int x) {
  if (unionFind[x] == -1)
    return x;
  return unionFind[x] = findSet(unionFind[x]);
}

void unionSet(int x, int y) { unionFind[findSet(x)] = y; }

void buildTree(int x, int y, int z) {
  maxWeightTreeEdges[x].push_back(make_pair(y, z));
  maxWeightTreeEdges[y].push_back(make_pair(x, z));
}

void kruskal() {
  initUnion();
  sort(s, s + m, cmp);
  for (int i = 0; i < m; i++)
    if (findSet(s[i].x) != findSet(s[i].y)) {
      unionSet(s[i].x, s[i].y);
      buildTree(s[i].x, s[i].y, s[i].z);
    }
}

// TODO: LCA
void BFS(int x, int deepth) {
  queue <pair<int, int> > Q;
  Q.push(make_pair(x, deepth));
  while (!Q.empty()) {
    pair<int, int> front = Q.front();
    Q.pop();
    dep[front.first] = front.second;
    for (int i = 0; i < maxWeightTreeEdges[front.first].size(); i++)
      if (dep[maxWeightTreeEdges[front.first][i].first] == -1) {
        Q.push(make_pair(maxWeightTreeEdges[front.first][i].first, front.second + 1));
        maxWeightTree[maxWeightTreeEdges[front.first][i].first].y = front.first;
        maxWeightTree[maxWeightTreeEdges[front.first][i].first].z = maxWeightTreeEdges[front.first][i].second;
      }
  }
}

void countDeepth() {
  for (int i = 1; i <= n; i++)
    if (dep[i] == -1)
      BFS(i, 0);
}

void countFW() {
  for (int i = 1; i <= n; i++)
    if(maxWeightTree[i].y) {
      f[i][0] = maxWeightTree[i].y;
      w[i][0] = maxWeightTree[i].z;
    }
  for (int j = 1; j <= 24; j++)
    for (int i = 1; i <= n; i++) {
      f[i][j] = f[f[i][j - 1]][j - 1];
      w[i][j] = min(w[i][j - 1], w[f[i][j - 1]][j - 1]);
    }
}
void countLog() {
  for (int i = 1; i <= n; i++)
    lg[i] = lg[i - 1] + (1 << lg[i - 1] + 1 == i);
}

void initLCA() {
  countLog();
  memset(dep, -1, sizeof(dep));
  countDeepth();
  countFW();
}



int lca(int x, int y) {
  int ans = INT_MAX;
  if (dep[x] < dep[y])
    swap(x, y);
  while (dep[x] > dep[y]) {
    
    ans = min(ans, w[x][lg[dep[x] - dep[y]]]);
    x = f[x][lg[dep[x] - dep[y]]];
  }
  if (x == y)
    return ans;
  for (int k = lg[dep[x]]; k >= 0; --k)
    if (f[x][k] != f[y][k]) {
      ans = min(ans, w[x][k]);
      ans = min(ans, w[y][k]);
      x = f[x][k];
      y = f[y][k];
    }
  ans = min(ans, w[x][0]);
  ans = min(ans, w[y][0]);
  return ans;
}

void input() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++)
    scanf("%d %d %d", &s[i].x, &s[i].y, &s[i].z);
}

void work() {
  int q;
  int x, y;
  initLCA();
  scanf("%d", &q);
  while (q--) {
    scanf("%d %d", &x, &y);
    if (findSet(x) != findSet(y)) {
      printf("-1\n");
      continue;
    }
    printf("%d\n", lca(x, y));
  }
  
}

int main(int argc, const char * argv[]) {
  input();
  kruskal();
  work();
  return 0;
}