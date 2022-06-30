#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x)  cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y)  cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec,s,n)  for(int i=s;i<s+n;i++){ cout<<vec[i]<<" ";} cout<<endl
#define input(vec,s,n) vector<int> vec(s+n);for(int i=s;i<s+n;i++){cin>>vec[i];}
// #define input(vec) for (auto &el : vec) cin >> el;
#define print(vec) for (auto &el : vec) cout << el<<" " ; cout << '\n'; 
#define fill(v,p) memset(v,p,sizeof(v))
#define all(v) v.begin(),v.end()
#define ini(_n)  int _n;cin>>_n;
#define inl(_n) ll _n;cin>>_n;
#define go  int tc;cin>>tc;while(tc--)
#define endl '\n'
#define fastio  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;


void solve(){
  ini(n);
  ini(m);
  string a(n,'0'),b(m,'0');
  ini(p);
  while(p--){
    ini(t);
    a[t%n]='1';
    b[t%m]='1';
  }
  ini(q);
  while(q--){
    ini(t);
    a[t%n]='1';
    b[t%m]='1';
  }
  // cout<<a<<"\n"<<b<<"\n";
  int i=0,j=0;
  int r=n,e=m;;
  while(n<m){
    a.push_back(a[i]);
    i=(i+1)%r;
    n++;
  }
  while(m<n){
    b.push_back(b[j]);
    j = (j + 1) % e;
    m++;
  }
  assert(m==n);
  cout<<a<<"\n"<<b<<"\n";
  bitset<100> f(a);
  bitset<100> d(b);
  f|=d;
  for(int i=0;i<m;i++){
    cout<<f[i];
  }
}


int main()
{
  // fastio;
  //go{
    solve();
  //}
  return 0;
}