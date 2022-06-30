#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x) 			 cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) 		 cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec) 	 for(int i=0;i<vec.size();i++){ cout<<vec[i]<<" ";} cout<<endl
#define input(vec,n) 	 for(int i=0;i<n;i++){cin>>vec[i];}
#define go 				 int t;cin>>t;while(t--)
#define fastio 			 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;
const int mod=1e9+7;
ll power(ll x, ll y,int mod){   //modular exponentiation
	ll res=1;
	while(y){
		if(y&1){  //y is odd 
			res=(x*res)%mod;
		}
		y/=2;
		x=(x*x)%mod;
	}
	return res;
}

ll dp(ll n,ll m,ll k){
    if(n==0) return 0;
    else if(m==0) return power(n,k,1e9+7);
    else{
        return dp(n-1,m,k)+ dp(n,m-1,k);
    }
}

int main()
{
    ll m,n,k;
    cin>>m>>n>>k;
    cout<<dp(n,m,k);
    return 0;
}