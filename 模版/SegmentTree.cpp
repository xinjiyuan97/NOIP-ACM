//
//  main.cpp
//  SegmentTree
//
//  Created by 辛济远 on 2018/3/25.
//  Copyright © 2018年 辛济远. All rights reserved.
//

#include <cstdio>
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x > y ? y : x)
using namespace std;

int sum[200005];
int A[100000];
int add[200005];
void pushUp(int o) {
  sum[o] = sum[o << 1] + sum[o << 1 | 1];
}

void pushDown(int o,int l, int r){
  if(add[o]){
    add[o << 1] += add[o];
    add[o << 1 | 1] += add[o];
    sum[o << 1] += add[o] * l;
    sum[o << 1 | 1] += add[o] * r;
    add[o]=0;
  }
}

void buildTree(int l, int r, int o){
  if(l == r) {
    sum[o] = A[l];
    return;
  }
  int mid = (l + r) >> 1;
  buildTree(l , mid, o << 1);
  buildTree(mid + 1, r, o << 1 | 1);
  pushUp(o);
}

void update(int k, int C, int l, int r, int o) {
  if(l == r){
    sum[o] += C;
    return;
  }
  int mid = (l + r) >> 1;
  if(k <= mid)
    update(k, C, l, mid, o << 1);
  else
    update(k, C, mid + 1, r, o << 1 | 1);
  pushUp(o);
}

void update(int L, int R, int C, int l, int r, int o) {
  if(L <= l && r <= R) {
    sum[o] += C * (r - l + 1);
    add[o] += C;
    return ;
  }
  int mid = (l + r) >> 1;
  pushDown(o, mid - l + 1, r - mid);
  
  if(L <= mid) update(L, R, C, l, mid, o << 1);
  if(R > mid) update(L, R, C, mid + 1, r, o << 1 | 1);
  pushUp(o);//更新本节点信息
}

int query(int L, int R, int l, int r, int o) {
  if(L <= l && r <= R)
    return sum[o];
  int mid = (l + r) >> 1;
  pushDown(o, mid - l + 1, r - mid);
  int res = 0;
  if(L <= mid)
    res += query(L, R, l, mid, o << 1);
  if(R > mid)
    res += query(L, R, mid + 1, r, mid << 1 | 1);
  return res;
}
