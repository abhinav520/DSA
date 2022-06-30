#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x) 			 cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) 		 cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec,n) 	 for(int i=0;i<n;i++){ cout<<vec[i]<<" ";} cout<<endl
#define input(vec,n) 	 for(int i=0;i<n;i++){cin>>vec[i];}
#define go 				 int t;cin>>t;while(t--)
#define fastio 			 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;
// int n=100000;
// int spf[n+1];  
// void sievePrimeFactor()
// {
// 	//AIM: create spf array with index as num and value as smallest prime factor
	
// 	for(int i=2;i<=n;i++){
// 		spf[i]=i;
// 	}
// 	for(int i=2;i<=n;i++){
// 		if(spf[i]==i){
// 			for(int j=i*i;j<=n;j+=i){
// 				if(spf[j]==j){
// 					spf[j]=i;
// 				}
// 			}
// 		}
// 	}
// 	while(n!=1){
// 		cout<<spf[n]<<" ";
// 		n/=spf[n];
// 	}
// 	cout<<endl;

// }
// int primes[50847535];

bool solve()
{
    ll a, b;
    cin >> a >> b;
    vector<ll> v;
    
    ll n=a;
    for (int d : {2, 3, 5}) {
        if(n%d==0){
            v.push_back(d);
        }
        while (n % d == 0) {
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int d=0;
    for (ll i = 7; i * i <= n; i+=increments[d++])
    {
        if (n % i == 0)
        {
            v.push_back(i);
            while(n%i==0){
                n/=i;
            }
        }
        if (d == 8)
            d = 0;
    }
    if(n>1){
        v.push_back(n);
    }
    for(auto x:v){
        if(b%x!=0){
            return false;
        }
    }
    return true;
}

int main()
{
    // int n=100000;
    // vector<bool> is_prime(n+1, true);
    // is_prime[0] = is_prime[1] = false;
    // for (int i = 2; i <= n; i++) {
    //     if (is_prime[i] && (long long)i * i <= n) {
    //         for (int j = i * i; j <= n; j += i)
    //             is_prime[j] = false;
    //     }
    // }
    go
    {
        if(solve()){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
    }
    return 0;
}
