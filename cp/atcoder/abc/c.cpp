#include <bits/stdc++.h>
using namespace std;

#define deb(x) 		cout << #x << "=" << x << endl
#define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef long long int ll;


void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    ll ans=0,ct=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        arr[i]%=200; //storing remainder
        // ct++;
        // ans+=ct;
    }
    // ans-=ct;

    sort(arr.begin(),arr.end());
    ct=0;
    ll temp=0;
    arr.push_back(-1);  //for handling last set
    for(int i=0;i<n;i++){
        if(arr[i]!=arr[i+1]){
            ans+=temp;
            temp=0;
            ct=0;
        }
        else{
            ct++;
            temp+=ct;
        }
    }
    cout<<ans<<endl;
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