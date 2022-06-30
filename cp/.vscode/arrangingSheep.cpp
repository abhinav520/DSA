#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 	//pbds
//pbds ordered_set (similar to set) plus *s.find_by_order(x) & s.order_of_key(x)
#include <ext/pb_ds/tree_policy.hpp> 	//pbds
using namespace __gnu_pbds;
using namespace std;

#define deb(x) 		cout << #x << "=" << x << endl
#define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
#define sp(x,y) 	fixed<<setprecision(y)<<x
#define setbits(x)  __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define inf			1e18
#define mod			1'000'000'007;
#define PI 			3.1415926535897932384626
#define endl		"\n"

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim){
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef long long int ll;
//--------------------------------------------------------------------------------------------


void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int m=0;
    vector<ll> vec;
    vec.reserve(n);
    for(int i=0;i<n;i++){
        if(s[i]=='*'){
            m++;
            vec.push_back(i);
        }   
    }
    int mid=m/2;
    int mid2=mid;
    ll ans=0;
    for(int i=mid-1;i>=0;i--){
        ans+=vec[mid]-vec[i]-1;
        vec[i]=vec[mid]-1;
        mid--;
    }
    for(int i=mid2+1;i<m;i++){
        ans+=vec[i]-1-vec[mid2];
        vec[i]=vec[mid2]+1;
        mid2++;
    }
    cout<<ans<<"\n";
}


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int tc=1;
    cin>>tc;

    while(tc--){
        solve();
    }

    return 0;
}