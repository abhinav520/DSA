//Given a string s of length n, consisting only of lowercase English letters, find the number of different substrings in this string.
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

int count_unique_substrings(string const&s){
  int n=s.size();
  const int p=31;
  const int m=1e9+9;
  vector<ll> p_pow(n);
  p_pow[0]=1;
  for(int i=1;i<n;i++){
    p_pow[i]=(p_pow[i-1]*p)%m;
  }
  vector<ll> hash(n+1,0);
  for(int i=0;i<n;i++){
    hash[i+1]=(hash[i]+(s[i]-'a'+1)*p_pow[i])%m;
  }
  int cnt=0;
  for(int l=1;l<=n;l++){
    set<ll> hash_set;
    for(int i=0;i<=n-l;i++){
      ll cur_hash=(hash[i+l]-hash[i]+m)%m;
      cur_hash=(cur_hash*p_pow[n-i-1])%m;
      hash_set.insert(cur_hash);
    }
    cnt+=hash_set.size();
  }
  return cnt;
}

int main()
{
  fastio;
  go{
    string s;
    cin>>s;
    cout<<count_unique_substrings(s)<<endl;
  }
  return 0;
}