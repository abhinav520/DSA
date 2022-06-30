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

bool check(int x,int n, vector<int> &v){
  int i=0,j=n-1;
  while(i<=j){
    while(v[i]==x) i++;
    while(v[j]==x) j--;
    if(v[i++]!=v[j--]) return false;
  }
  return true;
}
bool solve(){
  ini(n);
  vector<int> v(n);
  input(v, n);
  for(int i=0;i<n;i++){
    if(v[i]==v[n-1-i]) continue;
      return (check(v[i],n,v) || check(v[n-1-i],n,v));
  }
  return true;
}

int main()
{
  // fastio;
  go{
    
    if(solve()){
      cout<<"YES\n";
    }else{
      cout<<"NO\n";
    }
  }
  return 0;
}