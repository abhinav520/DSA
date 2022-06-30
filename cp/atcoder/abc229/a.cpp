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
  string a,b;
  cin>>a>>b;
  int n=a.length();
  int m=b.length();
  // int c=0;
  for(int i=1;i<=min(m,n);i++){
    int x=a[n-i]-'0';
    int y=b[m-i]-'0';
    if(x+y>9){
      // c=(x+y)/10;
      cout<<"Hard";
      return;
    }
  }
  cout<<"Easy";

}


int main()
{
  fastio;
  //go{
    solve();
  //}
  return 0;
}