#include <bits/stdc++.h>
using namespace std;

#define deb(x) 		cout << #x << "=" << x << endl
#define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef long long int ll;


void solve()
{
    int n;
    cin>>n;
    int arr[n+1]={0};
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        arr[t]=1;
    }
    int flag=1;
    for(int i=1;i<=n;i++){
        if(arr[i]==0) {
            flag=0;
            break;
        }
    } 
    if(flag==0) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;

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