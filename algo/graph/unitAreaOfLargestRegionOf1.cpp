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
#define fastio  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

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

/******************************************************************************************************************************************************/

// } Driver Code Ends
class Solution
{
  int dr[8] = {0, 0, 1, -1, 1, 1, -1, -1};
  int dc[8] = {1, -1, 0, 0, 1, -1, 1, -1};

public:
  // Function to find unit area of the largest region of 1s.
  bool isSafe(int i, int j, vector<vector<int>> &grid)
  {
    return (i >= 0 and j >= 0 and i < grid.size() and j < grid[0].size() and grid[i][j] == 1);
  }
  void dfs(vector<vector<int>> &grid, int i, int j, int *area)
  {
    if (grid[i][j] == 0)
      return;
    grid[i][j] = 0;
    for (int k = 0; k < 8; k++)
    {
      if (isSafe(i + dr[k], j + dc[k], grid))
      {
        *area = *area + 1;
        dbg(i,j);
        dfs(grid, i + dr[k], j + dc[k], area);
      }
    }
    return;
  }
  // Take action on vertex before leaving the vertex
  int findMaxArea(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();
    int mx = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int area = 0;
        if (grid[i][j] == 1)
        {
          dfs(grid, i, j, &area);
          mx = max(mx, area);
          grid[i][j] = 0;
        }
      }
    }
    return mx;
  }
};

// { Driver Code Starts.
signed main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> grid[i][j];
      }
    }
    Solution obj;
    int ans = obj.findMaxArea(grid);
    cout << ans << "\n";
  }
  return 0;
} // } Driver Code Ends