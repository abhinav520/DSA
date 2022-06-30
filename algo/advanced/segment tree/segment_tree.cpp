#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(0), cin.tie(0)
#define all(v) v.begin(), v.end()
#define endl '\n'
#define int int64_t

void build(vector<int> &seg_tree, vector<int> &a, int treeNode, int start, int end){
  if (start == end){
    seg_tree[treeNode] = a[start-1];
    return;
  }
  int mid = (start + (end - start)/2);
  build(seg_tree, a, 2 * treeNode, start, mid);
  build(seg_tree, a, 2 * treeNode + 1, mid+1, end);
  seg_tree[treeNode] = seg_tree[2 * treeNode] + seg_tree[2 * treeNode + 1];
}
void update(vector<int> &seg_tree,vector<int> &a, int treeNode, int start, int end, int idx, int val){
  if(start==end){
    if(start==idx){
      seg_tree[treeNode]=val;
      a[idx-1]=val;
    }
    return;
  }
  int mid = (start + (end - start)/2);
  update(seg_tree, a, 2 * treeNode, start, mid, idx, val);
  update(seg_tree, a, 2 * treeNode + 1, mid + 1, end, idx, val);
  seg_tree[treeNode] = seg_tree[2 * treeNode] + seg_tree[2 * treeNode + 1];
}
int query(vector<int> &seg_tree, int treeNode, int start, int end, int l, int r)
{
  if(l==start and r==end){
    return seg_tree[treeNode];
  }
  int mid = (start + (end - start) / 2);
  int left=0,right=0;
  if(l>=start and l<=mid){
    left = query(seg_tree, 2 * treeNode, start, mid, l, min(r,mid));
  }
  if(r>mid and r<=end){
    right = query(seg_tree, 2 * treeNode + 1, mid + 1, end, max(l,mid+1), r);
  }
  return left+right;
}
signed main()
{
  // fastio;
  int n;
  cin>>n;
  vector<int> seg_tree(4 * n);
  vector<int> a(n);
  for(auto &x:a) cin>>x;
  build(seg_tree, a, 1, 1, n);
  update(seg_tree,a,1,1,n,4,10);
  for(auto &x:seg_tree) cout<<x<<" ";cout<<endl;
  cout<<query(seg_tree,1,1,n,2,5)<<endl;
  return 0;
}