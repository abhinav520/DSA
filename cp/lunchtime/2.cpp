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

bool cmp(pair<int,int> a,pair<int,int> b){
    return b.second>a.second;
}
void solve(){
    ini(n);
    ini(k);
    string s;
    cin>>s;
    int cnt[27]={0};
    unordered_map<int,int> mp;
    int req[27]={0};
    for(auto c:s){
        int idx=c-'A'+1;
        mp[idx]++;
        cnt[idx]++;
        req[idx]++;
    }
    int i=0;
    int idx=s[0]-'A'+1;
    req[idx]++;
    i++;
    while(i<n){
        while(s[i]==s[i-1] && i<n){
            i++;
        }
        if(i>=n) break;
        idx = s[i] - 'A' + 1;
        req[idx]++;
        i++;
    }
    if(s[0]==s[n-1]){
        idx = s[0] - 'A' + 1;
        req[idx]-=2;
    }
    else{
        idx = s[0] - 'A' + 1;
        req[idx]--;
    }
    sort(mp.begin(),mp.end(),cmp);
    for(auto x:mp){
        cout<<x.first<<" "<<x.second<<"\n";
    }
}


int main()
{
    // fastio;
    go{
        solve();
    }
    return 0;
}