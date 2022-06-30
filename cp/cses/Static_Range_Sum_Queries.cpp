#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(0), cin.tie(0)
#define all(v) v.begin(), v.end()
#define endl '\n'
#define int int64_t



//solution for static range Xor query
signed main()
{
  fastio;
  int n,q;
  cin>>n>>q;
  int m= log2(n);
  vector<vector<int>> sparse_tab(m+1, vector<int> (n));
  for(int i=0;i<n;i++){
    cin>>sparse_tab[0][i];
  }
  for(int j=1;j<=m;j++){
    for(int i=0;i+(1<<j)-1<n; i++){
      sparse_tab[j][i]=(sparse_tab[j-1][i])^(sparse_tab[j-1][i+(1<<(j-1))]);
    }
  }
  vector<int> lg(n+1);
  lg[1]=0;
  for(int i=2;i<=n;i++){
    lg[i]=lg[i/2]+1;
  }
  for(int i=0;i<q;i++){
    int l,r;
    cin>>l>>r;
    l--,r--;
    int xr=0;
    for(int j=m;j>=0;j--){
      if((1<<j)<=(r-l+1)){
        xr^=sparse_tab[j][l];
        l+=(1<<j);
      }
    }
    cout<<xr<<endl;    
  }
  return 0;
}
/*[
  [3, 2, 4, 5, 1, 1, 5, 3], 
  [2, 2, 4, 1, 1, 1, 3, 0], 
  [2, 1, 1, 1, 1, 0, 0, 0], 
  [1, 0, 0, 0, 0, 0, 0, 0]
]*/
/*[
  [3, 2, 4, 5, 1, 1, 5, 3],
  [2, 2, 4, 1, 1, 1, 3, 2147483647],
  [2, 1, 1, 1, 1, 2147483647, 2147483647, 2147483647],
  [1, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647]
]*/
