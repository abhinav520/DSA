#include <bits/stdc++.h>
using namespace std;

#define deb(x) 		cout << #x << "=" << x << endl
#define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef long long int ll;


void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    
    if (c%2==0){
        if(a<0) a*=-1;
        if(b<0) b*=-1;
    }
    if(a==b || (c%2==0 && a+b==0)) cout<<"=";
    else
        (a<b)?cout<<"<":cout<<">";
}


int main()
{
    int tc=1;
    //cin>>tc;

    while(tc--){
        solve();
    }

    return 0;
}