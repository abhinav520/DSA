//Abhinav Singh
#include <bits/stdc++.h>
using namespace std;

//--------------------debugTemplate-------------------------//
bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "["; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "]"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename Head> void dbg_out(string var, const Head &H) { cerr << var << " = " << H << endl; }
template <typename Head, typename ...Tail> void dbg_out(string var, const Head &H, const Tail &...T) { for (int i = 0, b = 0; i < int(var.size()); i++) { if (var[i] == '(' || var[i] == '{') { b++; } else if (var[i] == ')' || var[i] == '}') { b--; } else if (var[i] == ',' && b == 0) { cerr << var.substr(0, i) << " = " << H << " | "; dbg_out(var.substr(var.find_first_not_of(' ', i + 1)), T...); break; } } }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
#ifndef ONLINE_JUDGE
#define dbg(...) debug = true, dbg_out(#__VA_ARGS__, __VA_ARGS__), debug = false
#else
#define dbg(...)
#endif
//--------------------debugTemplate-------------------------//

#define int int64_t
#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define ini(_n)  int _n;cin>>_n;
#define input(vec,s,n) vector<int> vec(s+n);for(int i=s;i<s+n;i++){cin>>vec[i];}
#define output(vec,s,n)  for(int i=s;i<s+n;i++){ cout<<vec[i]<<" ";} cout<<endl
#define inpu(vec) for (auto &el : vec) cin >> el;
#define fill(v,p) memset(v,p,sizeof(v))
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(x) ((int)(x).size())
#define endl '\n'
#define fastio  ios_base::sync_with_stdio(0), cin.tie(0)

typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<pi> vpi;
typedef set<int> si;
typedef set<char> sc;
typedef set<pi> spi;
typedef multiset<int> mst;
typedef map<int,int> mi;
typedef map<char,int> mc;
typedef unordered_map<int,int> umi;
typedef unordered_map<char,int> umc;

#define setbits(x)  __builtin_popcountll(x) // returns number of 1-bits of x
#define trailing0(x) __builtin_ctzll(x) //returns num of trailing 0-bits of x
#define leading0(x) __builtin_clz(x) //returns num of leading 0-bits of x
#define firstbitpos(x) __builtin_ffs(x) //returns 1 + indexOf(least significant 1-bit)
#define binary(n) bitset<32>(n)
#define seal(n) (n&1)?(n/2+1):(n/2)
const int mod= 1000000007;
const int mod2= 998244353;
//functions
int mpow(int base, int exp){int ans=1; while(exp){if(exp&1) ans=(ans*1LL*base)%mod; base=(base*base)%mod; exp>>=1;} return ans;}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}

/******************************************************************************************************************************************************/
int parent[110];
int siz[110];
int cnt[110];

void make_sets(int v)
{
  parent[v] = v;
  siz[v] = 1;
}

int find_sets(int v)
{
  if (parent[v] == v)
    return v;
  return parent[v] = find_sets(parent[v]);
}

void union_sets(int a, int b)
{
  a = find_sets(a);
  b = find_sets(b);
  if (a != b)
  {
    if (siz[a] < siz[b])
    {
      swap(siz[b], siz[a]);
    }
    parent[b] = a;
    siz[a] += siz[b];
  }
}
/**************************************************************/
vector<vector<int>> lang(110);
int n,m;
void solve(){
  cin>>n>>m;
  bool f=false;
  rep(i,1,n+1){
    ini(t);
    if(t>0) f=true;
    while(t--){
      ini(j);
      lang[j].emplace_back(i);
    }
  }
  // for (int i = 1; i <= m; i++)
  // {
  //   cout << "Language " << i << " is known by - ";
  //   print(lang[i]);
  // }
  // cout<<endl;
  if(f==false){
    cout<<n<<endl;
    return;
  }
  rep(i,1,n+1) make_sets(i);

  for(int i=1;i<=m;i++){
    if(lang[i].size()==0) continue;
    int  mn=n+1;
    for(auto x:lang[i]){
      mn=min(mn,x);
      if(find_sets(x)!=x){
        mn=find_sets(x);
        break;
      }
    }
    int vis[n+1];
    fill(vis,0);
    for(int k=0;k<(lang[i].size())-1;k++){
      union_sets(lang[i][k+1],lang[i][k]);
    }
    // for(auto x:lang[i]){
    //   // if(vis[x]==0)
    //     union_sets(,x);
    // }
  }
  // for(int i=1;i<=n;i++){
  //   cout<<"Parent of "<<i<<" - "<<find_sets(i)<<endl;
  // }
  int res=0;
  rep(i,1,n+1){
    if(find_sets(i)==i) res++;
  }
  cout<<res-1<<endl;
}


signed main()
{
  fastio;
  int tc=1;
  // cin>>tc;
  for(int testcase=1;testcase<=tc;testcase++){
    dbg(testcase);
    solve();
  }

  return 0;
}