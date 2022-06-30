#include <bits/stdc++.h>
using namespace std;

#define deb(x) 		cout << #x << "=" << x << endl
#define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
#define fo(i,a,n,k) for(int i=a;i<n;i+=k)
typedef long long int ll;

int arr[100001];
int jarruri[16670];

void solve()
{
    ll m,n;
    cin>>m>>n;
    if(m==1) m++;
    ll z=1LL*sqrt(n);
    ll prime[n-m+1];
    fo(i,0,n-m+1,1) prime[i]=m+i;
    fo(i,0,n-m+1,1){
        for(int j=i;j<=z;j+=i){
            if(prime[i]%jarruri[j]==0){
                prime[i]=0;
            }
       }
    }
    fo(i,0,z,1){
        if(prime[i]==i){
            cout<<prime[i]<<endl;
        }
    }
}


int main()
{
    int tc=1;
    cin>>tc;
    arr[1]=1;
    fo(i,2,100000,1){
        if(arr[i]==0)
        fo(j,i*i*1LL,100000,i){
            arr[j]=1;
        }
    }

    int r=0;
    fo(i,2,100000,1){
        if(arr[i]==0){
            jarruri[r++]=arr[i];
            deb(r);
        }
    }
    deb(r);
    while(tc--){
        solve();
        cout<<endl;
    }

    return 0;
}


//-------atcoder E:gcd(hard)  atcoder----
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int mod=1e9+7;
// ll power(ll a, ll b){ return b?(power(a*a%mod,b/2)%mod*(b&1 ? a:1))%mod:1;}

// int main(){
//   int n,k;
//   cin>>n>>k;
//   ll dp[k+1]={0};
//   for(int i=k;i>=1;i--){
//     dp[i]=power(k/i,n);
//     for(int j=2*i;j<=k;j+=i){
//     	dp[i]-=dp[j];
//     }
//   }
//   ll ans=0;
//   for(int i=1;i<=k;i++){
//   	ans+=(i*dp[i]%mod)%mod;
//   }
//   cout<<ans%mod;
//   return 0;
// }