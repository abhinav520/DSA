#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define all(v) v.begin(), v.end()
#define endl '\n'
#define int int64_t
#define MAXN 200000
int n, t[4 * MAXN];
void build(vector<int> &a, int v, int tl, int tr)
{
  if (tl == tr)
  {
    t[v] = a[tl];
  }
  else
  {
    int tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    t[v] = min(t[v * 2] , t[v * 2 + 1]);
  }
}
int minimum(int v, int tl, int tr, int l, int r)
{
  if (l > r)
    return INT64_MAX;
  if (l == tl && r == tr)
  {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return min(minimum(v * 2, tl, tm, l, min(r, tm)), minimum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}
void update(int v, int tl, int tr, int pos, int new_val)
{
  if (tl == tr)
  {
    t[v] = new_val;
  }
  else
  {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(v * 2, tl, tm, pos, new_val);
    else
      update(v * 2 + 1, tm + 1, tr, pos, new_val);
    t[v] = min(t[v * 2] , t[v * 2 + 1]);
  }
}

signed main()
{
  fastio;
  int q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &x : a)
    cin >> x;
  build(a, 1, 0, n-1);
  for(int i=0;i<q;i++){
    int c,l,r;
    cin>>c>>l>>r;
    l--,r--;
    if(c==1){
      update(1,0,n-1,l,r+1);
    }
    else cout<<minimum(1,0,n-1,l,r)<<endl;
  }
  return 0;
}