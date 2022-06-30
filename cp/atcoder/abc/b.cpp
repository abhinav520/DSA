#include <bits/stdc++.h>
using namespace std;

#define deb(x) 		cout << #x << "=" << x << endl
#define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef long long int ll;


void solve()
{
    int n;
    cin>>n;
    int i=1;
    while(true){
        if(2*n<=(i*(i+1))){
            break;
        }
        i++;
    }
    cout<<i<<endl;
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