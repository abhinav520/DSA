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

bool cmp(pair<ll,ll> a, pair<ll,ll>b){
    return a.second<b.second;
}

int main()
{
    int n;cin>>n;
    ll k;cin>>k;
    vector<pair<ll,ll>> st(n);
    for(int i=0;i<n;i++){
        int t;cin>>t;
        st[i]={t,i};
    }
    sort(st.begin(),st.end());
    ll u=k/n;
    k=k-u*n;
    for(int i=0;i<n;i++){
        if(i<k){
            st[i].first=k+u;
        }
        else{
            st[i].first=u;
        }
    }
    sort(begin(st),end(st),cmp);
    for(int i=0;i<n;i++){
        cout<<st[i].first<<endl;
    }
    return 0;
}