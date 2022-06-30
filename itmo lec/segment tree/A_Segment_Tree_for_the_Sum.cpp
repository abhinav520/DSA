#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
typedef long long ll;


class Segtree{
  int size;
  public:
  vector<ll> sums;
    Segtree(int n){
      size=1;
      while(size<n) size*=2;
      sums.assign(2*size,0LL);
    }
    void set(int i, int v);
    void set(int i, int v, int x, int lx, int rx);
    ll sum(int i, int v);
    ll sum(int i, int v, int x, int lx, int rx);
};

void Segtree::set(int i, int v){
  set(i,v,0,0,size);
}

void Segtree::set(int i, int v, int x, int lx, int rx){
  if(rx-lx==1){
    sums[x]=v;
    return;
  }
  int m=(lx+rx)/2;
  if(i<m){
    set(i,v,2*x+1,lx,m);
  }
  else{
    set(i,v,2*x+2,m,rx);
  }
  sums[x]=sums[2*x+1]+sums[2*x+2];
}

ll Segtree::sum(int l, int r){
  return sum(l,r,0,0,size);
}

ll Segtree::sum(int l, int r, int x, int lx, int rx){
  if(l>=rx or r<=lx) return 0;
  if(lx>=l and rx<=r) return sums[x];
  int m=(lx+rx)/2;
  return sum(l,r,2*x+1,lx,m)+sum(l,r,2*x+2,m,rx);
}

int main()
{
  fastio;
  int n,m;
  cin>>n>>m;
  Segtree seg(n);
  for(int i=0;i<n;i++){
    int x;cin>>x;
    seg.set(i,x);
  }
  
  for(int j=0;j<m;j++){
    int choice,l,r, i,v;
    cin>>choice;
    if(choice==1){
      cin>>i>>v;
      seg.set(i,v);
    }
    else{
      cin>>l>>r;
      cout<<seg.sum(l,r)<<"\n";
    }
  }
  return 0;
}