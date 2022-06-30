#include <bits/stdc++.h>
using namespace std;

#define deb(x) 		cout << #x << "=" << x << endl
#define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef long long int ll;


void solve()
{
    double a,b;
    cin>>a>>b;
    cout<<b*a/100;
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