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
typedef long long int ll;
const int m = 998244353;
ll power(ll x, ll y, int m)
{ //modular exponentiation
  ll res = 1;
  while (y)
  {
    if (y % 2)
    { //y is odd
      res = (x * res) % m;
    }
    y /= 2;
    x = (x * x) % m;
  }
  return res;
}

void solve()
{
  inl(n);
  if(n==1){
    cout<<1<<endl;
    return;
  }
  ll a,b,c,d;
  if((n+1)%2==0){
    ll hg=(n+1)/2;
    cout<<(((n*hg)%m)*hg)%m<<endl;
  }
  else{
    ll hg=n/2;
    cout<< ((((1LL* hg * (n + 1) % m) * (n + 1)) % m) * 499122177)%m << endl;
  }
}

int main()
{
  fastio;
  go{
    solve();
  }
  return 0;
}