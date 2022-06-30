#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x) 			 cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) 		 cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec,n) 	 for(int i=0;i<n;i++){ cout<<vec[i]<<" ";} cout<<endl
#define input(vec,n) 	 for(int i=0;i<n;i++){cin>>vec[i];}
#define go 				 int t;cin>>t;while(t--)
#define fastio 			 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;


int main()
{
  int s,t,x;
  cin>>s>>t>>x;
  t*=100;
  s*=100;
  if(t<s){
    t=t+2400;
  }
  x=x*100+30;
  if(x<s && t>=2400){
    x=x+2400;
  }
  deb(x);
  deb(s);
  deb(t);
  if(s<=x && x<t) cout<<"Yes";
  else cout<<"No";
  return 0;
}