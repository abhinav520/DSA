#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x) 					 cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) 			 cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec,s,n)  for(int i=s;i<s+n;i++){ cout<<vec[i]<<" ";} cout<<endl
#define input(vec,s,n) 	 vector<int> vec(s+n);for(int i=s;i<s+n;i++){cin>>vec[i];}
#define ini(_n) 				 int _n;cin>>_n;
#define inl(_n) 				 ll _n;cin>>_n;
#define go 							 int tc;cin>>tc;while(tc--)
#define fastio 					 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;


void solve(){
    ini(n);
    ini(p);
    ini(q);
    string s;
    cin>>s;
    p=abs(p);
    q=abs(q);
    if(p+q>n){
        cout<<"NO\n";
        return;
    }
    // int one=0;
    // for(auto &c:s){
    //     if(c=='1') one++;
    // }
    // int o=n-one;
    // int mx=p+q;
    // bool flag=false;
    int arr[2]={0};
    int idx=0;
    for (auto &c : s)
    {
        if(c=='0'){
            idx=!idx;
        }
        arr[idx]++;
    }
    if(arr[0]>=p && arr[1]>=q && (arr[0]-p)%2==0 && (arr[1]-q)%2==0){
        cout<<"YES\n";
        return;
    }
    if(arr[0]>=q && arr[1]>=p && (arr[0]-q)%2==0 && (arr[1]-p)%2==0){
        cout<<"YES\n";
        return;
    }
    cout<<"No\n";

}


int main()
{
    // fastio;
    go{
        solve();
    }
    return 0;
}