//Abhinav Singh
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define all(x) begin(x),end(x)
const int N = 510;
const int inf = 1e9 + 6;

int n;
void solve(){
  cin>>n;
  vector<vector<long long>> g(n, vector<long long>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>g[i][j];
    }
  }
  vector<int> x(n);
  for(auto &f:x){
    cin>>f;
  }
  stack<long long> ans;
  reverse(all(x));
  int l=0;
  for(auto k:x){
    k--;
    l++;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
      }
    }
    long long cnt=0;
    for(int i=0;i<l;i++){
      for (int j = 0; j < l; j++){
        cnt+=g[x[i]-1][x[j]-1];
      }
    }
    ans.push(cnt);
  }
  while(!ans.empty()){
    cout<<ans.top()<<" ";
    ans.pop();
  }
  cout<<endl;
}


signed main()
{
  fastio;
  int tc=1;
  // cin>>tc;
  for(int testcase=1;testcase<=tc;testcase++){
    solve();
  }

  return 0;
}