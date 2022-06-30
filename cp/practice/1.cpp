#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x)  cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y)  cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec,s,n)  for(int i=s;i<s+n;i++){ cout<<vec[i]<<" ";} cout<<endl

#define input(vec) for (auto &el : vec) cin >> el;
#define print(vec) for (auto &el : vec) cout << el<<" " ; cout << '\n'; 
#define fill(v,p) memset(v,p,sizeof(v))
#define all(v) v.begin(),v.end()
#define ini(_n)  int _n;cin>>_n;
#define inl(_n) ll _n;cin>>_n;
#define go  int tc;cin>>tc;while(tc--)
#define endl '\n'
#define fastio  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;

void solve(){
  inl(n);
  // vector<ll> factors;
  // factors.push_back(n);
  // for(ll i=2;i*i<=n;i++){
  //   if(n%i==0){
  //     factors.push_back(i);
  //     if(n/i != i) factors.push_back(n/i);
  //   }
  // }
  // vector<ll> ans;
  // for(auto x:factors){
  //   ans.push_back(n/)
  // }
  vector<ll> ans;
  ans.push_back(0);
  for(ll i=1;i*i<=n;i++){
    ans.push_back(i);
  }
  int e=sqrt(n);
  if(ans.back()!=n/e){
    ans.push_back(n/e);
  }
  for(ll i=sqrt(n)-1;i>=1;i--){
    ans.push_back(n/i);
  }
  cout<<ans.size()<<"\n";
  for(auto &x:ans){
    cout<<x<<" ";
  }
  cout<<endl;
}

int main()
{
  go{
    solve();
  }
  return 0;
}