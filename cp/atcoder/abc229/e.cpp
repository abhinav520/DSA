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
  // input(b,1,2*n);
  if (n == 1)
  {
    ini(u);
    ini(v);
    if(u==v)
    {
      cout << u << endl;
      return;
    }
    else
    {
      cout << -1 << endl;
      return;
    }
  }
  map<int,int> mp;
  for(int i=0;i<2*n;i++){
    int g;
    cin>>g;
    mp[g]++;
  }
  if(mp.size()!=n) {cout<<-1<<endl;return;}
  vector<int> v(n);
  auto it = mp.begin();
  int j=1;
  int k=0;
  
  while(j!=n+1){
    int i=(*it).first;
    int val=(*it).second;
    // deb(val);
    if(j==n){
      if (val != 1)
      {
        cout << -1 << endl;
        return;
      }
    }
    else if(j==ceil(n/2.0)){
      if(val !=3)
      {
        cout << -1 << endl;
        return;
      }
    }
    else 
    {
      if (val != 2)
        {cout << -1 << endl;
      return;}
    }
    v[k++]=i;
    j++;
    it++;
  }
  
  for(auto c:v){
    cout<<c<<" ";
  }
  cout<<endl;
}


int main()
{
  // fastio;
  go{
    solve();
  }
  return 0;
}