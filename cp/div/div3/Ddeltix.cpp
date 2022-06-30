#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x) 					 cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) 			 cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec,s,n)  for(int i=s;i<s+n;i++){ cout<<vec[i]<<" ";} cout<<endl
#define input(vec,s,n) 	 vector<ll> vec(s+n);for(int i=s;i<s+n;i++){cin>>vec[i];}
#define ini(_n) 				 int _n;cin>>_n;
#define inl(_n) 				 ll _n;cin>>_n;
#define go 							 int tc;cin>>tc;while(tc--)
#define fastio 					 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;


void solve(){
  ini(n);
  inl(h);
  input(a,0,n);
  if(n==1){
    cout<<h<<"\n";
    return;
  }
  ll l=1,r=h;
  while(l<r){
    ll mid=(l+r)/2;
    ll m=0;
    for(int i=0;i<n-1;i++){
      m+=min(mid,a[i+1]-a[i]);
    }
    m+=mid;
    if(m>h){
      r=mid;
    }
    else if(m<h){
      l=mid+1;
    }
    else{
      cout<<mid<<"\n";
      return;
    }
  }
  cout << l << "\n";
}


int main()
{
  // fastio;
  go{
    // deb(tc);
    solve();
  }
  return 0;
}