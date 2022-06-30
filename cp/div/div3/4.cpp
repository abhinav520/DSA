#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x) 					 cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) 			 cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec,n) 	 for(int i=0;i<n;i++){ cout<<vec[i]<<" ";} cout<<endl
#define input(vec,n) 		 for(int i=0;i<n;i++){cin>>vec[i];}
#define ini(_n) 				 int _n;cin>>_n;
#define inl(_n) 				 ll _n;cin>>_n;
#define go 							 int tc;cin>>tc;while(tc--)
#define fastio 					 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;

bool solve(int n, vector<int> &w)
{
  vector<int> b(n+1), p(n);
  int root;
  for (int i = 1; i <= n; i++)
  {
    int g;
    cin >> g;
    b[i] = g;
    if (i == g)
      root = g;
  }
  input(p, n);
  // vector<vector<int>> adj(n);
  // for (int i = 0; i < n; i++)
  // {
  //   adj[b[i]].emplace_back(i);
  // }
  if(p[0]!=root) return false;
  w[root]=0;
  int mx=0;
  for(int i=1;i<n;i++){
    int node=p[i];
    // deb(node);
    int papa=b[node];
    // deb(papa);
    int papaval=w[papa];
    // deb(papaval);
    if(papaval==-1) return false;
    mx++;
    w[node]=mx;
    mx+=papaval;
    // deb(nodeval);
    // cout<<endl;
  }
  return true;
}

int main()
{
  // fastio;
  go
  {
    ini(n);
    vector<int> w(n+1,-1);
    if (solve(n, w))
    {
      for(int i=1;i<=n;i++){
        cout<<w[i]<<" ";
      }
      cout<<endl;
    }
    else
    {
      cout << -1 << endl;
    }
  }
  return 0;
}