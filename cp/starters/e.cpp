#include <bits/stdc++.h>
using namespace std;

#define deb(x) 		cout << #x << "=" << x << endl
#define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
const int m=1e9+7;
typedef long long int ll;

ll ncr(ll n,ll r){
    if(r>n-r) r=n-r;
    unsigned long long res=1;
    for(int i=0;i<r;i++){
        //res%=m;
        res=(res*(n-i));
        res/=(i+1);
        // if(i>=900000)
        // deb(res);        
    }
    return res%m;
}

ll solve(){
    ll n,m,k;
    cin>>n>>m>>k;   //n<=m+k;
    if(n>m+k) return 0;
    ll a=ncr(n+m,n);
    if(n==k) return a;
    ll b=ncr(n+m,n-(k+1));
    //deb(a);deb(b);
    return (a-b)%m; 
}
int main()
{
    cout<<solve()<<endl;
    return 0;
}