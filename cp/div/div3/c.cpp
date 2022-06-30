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
  ini(k);
  input(a,1,n);
  for(int i=1;i<=k;i++){
    int ugly=0;
    int j=1,k=1;
    while(a[j]==i) j++;
    k=j;
    j++;
    while(j<=n)
    {
      if(a[j]==i) continue;
      if(a[j]!=a[k]) {
        ugly++;
        k=j;
      }
    }
    cout<<ugly<<endl;
  }
}


int main()
{
  fastio;
  go{
    solve();
  }
  return 0;
}