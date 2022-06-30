#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x) 					 cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) 			 cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec,s,n)  for(int i=s;i<s+n;i++){ cout<<vec[i]<<" ";} cout<<endl
#define input(vec,s,n) 	 vector<int> vec(s+n);for(int i=s;i<s+n;i++){cin>>vec[i];}
#define ini(_n) 				 int _n;cin>>_n;
#define inl(_n) 				 ll _n;cin>>_n;
#define go 							 int tc;cin>>tc;while(tc--)
#define fastio 					 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef unsigned long long int ll;

bool cmp(pair<ll, int> a, pair<ll, int>b)
{
  double g=a.first/a.second;
  double h=b.first/b.second;
  return g>h;
}
void solve(){
  ini(n);
  inl(w);
  vector<pair<ll,int>> v(n);
  for(int i=0;i<n;i++){
    inl(a);
    ini(b);
    v[i]={a,b};
  }
  sort(v.begin(),v.end(),greater<pair<ll,int>>());
  // for (int i = 0; i < n; i++)
  // {
  //   cout<<v[i].first<<" "<<v[i].second<<endl;
  // }
  ll cnt=0;
  int i=0;
  while(w && i<n){
    ll f=v[i].first;
    ll j=v[i].second;
    if(j>w){
      j=w;
    }
    w-=j;
    assert(f*j);
    cnt+=(f*j);
    i++;
  }
  cout<<cnt<<endl;
}


int main()
{
  fastio;
  //go{
    solve();
  //}
  return 0;
}