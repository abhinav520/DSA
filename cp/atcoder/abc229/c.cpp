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
  string s;cin>>s;
  ini(k);
  int n=s.length();
  int i=0,j=0;
  int c=k;
  int mx=0;
  while(i<n){
    if(c==0){
      if(s[i] == 'X')
        i++;
      mx = max(mx, (i - j));
    }
    if(c>0){
      if(s[i]=='X') i++;
      else{
        c--;
        i++;
      }
    }
    else{
      
      if(s[j]=='.'){
        c++;
        j++;
      }
      else{
        j++;
      }
    }
  }
  mx = max(mx, (i - j));
  cout<<mx;
}


int main()
{
  fastio;
  //go{
    solve();
  //}
  return 0;
}