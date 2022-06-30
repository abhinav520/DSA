#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x) 					 cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) 			 cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec,n) 	 for(int i=0;i<n;i++){ cout<<vec[i]<<" ";} cout<<endl
#define input(vec,n) 		 for(int i=0;i<n;i++){cin>>vec[i];}
#define ini(_n) 				 int _n;cin>>_n;
#define inl(_n) 				 ll _n;cin>>_n;
#define go 							 int tc;cin>>tc;while(tc--)
#define fastio 					 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;

const int p=31;
const int mod=1e9+9;
const int N=1e6+5;
vector<ll> ppow(N);

bool solve(string &s,string &pat,vector<ll> &v){
  int n=s.length();
  int m=pat.length();
  int phsh=0;
  for(int i=0;i<m;i++){
    phsh=(phsh+(pat[i]-'a'+1)*ppow[i])%mod;
  }
  vector<ll> hash(n + 1, 0);
  for(int i = 0; i < n; i++){
    hash[i + 1] = (hash[i] + (s[i] - 'a' + 1) * ppow[i]) % mod;
  }
  bool flag=false;
  for(int i=0;i<=n-m;i++){
    ll cur_hash = (hash[i + m] - hash[i] + mod) % mod;
    // cur_hash = (cur_hash * ppow[n - i - 1]) % mod;
    if(cur_hash==phsh*ppow[i]%mod){
      v.emplace_back(i);
      flag=true;
    }
  }
  
  return flag;
}


int main()
{
  fastio;
  ppow[0]=1;
  for(int i=1;i<N;i++){
    ppow[i]=(ppow[i-1]*p)%mod;
  }
  go{
    string s,pat;
    cin>>s>>pat;
    vector<ll> v;
    if(solve(s,pat,v)){
      cout<<v.size()<<endl;
      for(auto &x:v){
        cout<<x+1<<" ";
      }
      cout<<endl;
    }else{
      cout<<"Not Found\n";
    }
    cout<<endl;
  }
  return 0;
}