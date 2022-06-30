//Abhinav Singh
#include <bits/stdc++.h>
using namespace std;
 
//---------------------------------------------------------------------//
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
//---------------------------------------------------------------------//
 
#define int int64_t
#define ini(_n)  int _n;cin>>_n;
#define sni(_s)  string _s;cin>>_s;
#define input(vec,s,n) vector<int> vec(s+n);for(int i=s;i<s+n;i++){cin>>vec[i];}
#define output(vec,s,n)  for(int i=s;i<s+n;i++){ cout<<vec[i]<<" ";} cout<<endl
#define inpu(vec) for (auto &el : vec) cin >> el;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define fil(v,p) fill(all(v),p)
#define mem(v,p) memset(v,sizeof(v),p)
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define sz(x) ((int)(x).size())
#define endl '\n'
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define fastio  ios_base::sync_with_stdio(0), cin.tie(0)
 
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pi> vpi;
typedef set<int> si;
typedef set<string> ss;
typedef set<pi> spi;
typedef multiset<int> mst;
typedef map<int,int> mi;
typedef map<char,int> mci;
typedef unordered_map<int,int> umi;
typedef unordered_map<char,int> umc;
 
template <typename T> using vv = vector<vector<T>>;
template <typename T> using mxpq = priority_queue<T>;
template <typename T> using mnpq = priority_queue<T, vector<T>, greater<T>>;
#define setbits(x)  __builtin_popcountll(x) // returns number of 1-bits of x
#define trailing0(x) __builtin_ctzll(x) //returns num of trailing 0-bits of x
#define leading0(x) __builtin_clzll(x) //returns num of leading 0-bits of x
#define firstbitpos(x) __builtin_ffsll(x) //returns 1 + indexOf(least significant 1-bit)
#define binary(n) bitset<32>(n)
#define seal(n,m) (n%m!=0)?(n/m+1):(n/m)
 
const int mod= 1000000007, mod2= 998244353;
 
//functions
int mpow(int base, int exp, int mod=1000000007){int ans=1; while(exp){if(exp&1) ans=(ans*1LL*base)%mod; base=(base*base)%mod; exp>>=1;} return ans;}
//extendedgcd gives solution of ax+by=c and to have solution c%gcd(a,b) should be 0. Its genereal sol is [x+(k*a)/gcd,y-(k*b)/gcd] where k is Integer
void extendgcd(int a, int b, int *v){if (b == 0){v[0] = 1; v[1] = 0;v[2] = a;return;}extendgcd(b, a % b, v);int x = v[1];v[1] = v[0] - v[1] * (a / b);v[0] = x;return;}
int mminv(int a, int b){int arr[3];extendgcd(a, b, arr);return (arr[0]%b+b)%b;} // if b is prime just do mpow(a,b-2,b)
vector<pi> factor(int x){vector<pi> ans; for (int i = 2; i * i <= x; i++) if (x % i == 0) {ans.push_back({i, 1}); while ((x /= i) % i == 0) ans.back().second++;} if (x != 1) ans.push_back({x, 1}); return ans;}
template <class T> vector<T> divisor(T x){ vector<T> ans; for (T i = 1; i * i <= x; i++) if (x % i == 0) { ans.push_back(i); if (i * i != x) ans.push_back(x / i);}return ans;}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
template <class t> void random_shuffle(vector<t> &a) { for(int i=0;i<size(a);i++) swap(a[i], a[rand(0, i + 1)]); }
 
/**************************************************************************************************************************************************/
const int N=2e5+10, inf=1e18+10;
int n, m, sx, sy, ex, ey;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
char dir[]={'D','R','U','L'};
 
bool isValid(vector<vector<int>> &g, vector<vector<int>> &vis, int x, int y)
{
  return (x>=0 and y>=0 and x<n and y<m and vis[x][y]==0 and g[x][y]==1);
}

 
void solve(){
  cin>>n>>m;
  vector<vector<int>> g(n, vi(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      char c;cin>>c;
      if(c=='#') g[i][j]=0;
      else if(c=='.') g[i][j]=1;
      else if(c=='A') {g[i][j]=1;sx=i;sy=j;}
      else {g[i][j]=1;ex=i;ey=j;}
    }
  }
  static int dr[4] = {-1, 0, 1, 0};
  static int dc[4] = {0, -1, 0, 1};
  // static int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  // static int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  
  auto e = [&] (int r, int c) {
      return 0 <= r && r < n && 0 <= c && c < m;  
  };
  auto grid_bfs = [&](const vector<pair<int, int>> &source, vector<vector<int>> &d, vector<vector<int>> &prev_steps)
  {
    d.assign(n, vector<int>(m, inf));
    queue<pair<int, int>> q;
    for (auto &p : source)
    {
      int r = p.first;
      int c = p.second;
      q.emplace(r, c);
      d[r][c] = 0;
    }
    while (!q.empty())
    {
      int r = q.front().first;
      int c = q.front().second;
      q.pop();
      for (int dir = 0; dir < 4; dir++)
      {
        int nr = r + dr[dir], nc = c + dc[dir];
        if (e(nr, nc) && d[r][c] + 1 < d[nr][nc])
        {
          q.emplace(nr, nc);
          prev_steps[nr][nc]=dir;
          d[nr][nc] = d[r][c] + 1;
        }
      }
    }
  };
  vector<vector<int>> d;
  vector<vector<int>> prev_steps(n, vi(m));
  grid_bfs({{sx, sy}}, d, prev_steps);
  if(d[sx][sy]==inf){
    no;
  }
  else{
    yes;
    cout<<d[ex][ey]<<endl;
    while(sx!=ex and sy!=ey){
      
    }
  }
}
 
 
signed main()
{
  fastio;
  int tc=1;
  // cin>>tc;
  for(int testcase=1;testcase<=tc;testcase++){
    //dbg(testcase);
    solve();
  }
 
  return 0;
}