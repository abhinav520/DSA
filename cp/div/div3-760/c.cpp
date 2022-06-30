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

void solve(){
  int n;
  cin >> n;
  int o = 0, e = 0;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    int a;
    cin >> a;
    v[i] = a;
    if (a %2)
    {
      o++;
    }
    else
      e++;
  }
  int diff = abs(e - o);
  int ans = 0;
  if (diff >= 2)
  {
    cout << -1 << endl;
    return;

  }

  if (o > e)
  {
    int i = 0, j = 1;
    if ((v[i] % 2 )== 0)
    {
      while (v[j] % 2 == 0)
      {
        j++;
      }
      ans += j - i;
      swap(v[i], v[j]);
    }
    i = 1, j = 1;
    while (i < n)
    {
      if ((i % 2) == 1)
      {
        j = i;
        while (j < n && (v[j] % 2) == 1)
        {
          j++;
        }
        ans += j - i;
        swap(v[j], v[i]);
        i++;
      }
      else
      {
        j = i;
        while (j < n && (v[j] % 2)==0)
        {
          j++;
        }
        ans += j - i;
        swap(v[j], v[i]);
        i++;
      }
    }
  }
  else if (e > o)
  {
    int i = 0, j = 1;
    if ((v[i] % 2)==1)
    {
      while ((v[j] % 2)==1)
      {
        j++;
      }
      ans += j - i;
      swap(v[i], v[j]);
    }
    i = 1, j = 1;
    while (i < n)
    {
      if (i % 2==1)
      {
        j = i;
        while (j < n && (v[j] % 2) == 0)
        {
          j++;
        }
        ans += j - i;
        swap(v[j], v[i]);
        i++;
      }
      else
      {
        j = i;
        while (j < n && (v[j] % 2) == 1)
        {
          j++;
        }
        ans += j - i;
        swap(v[j], v[i]);
        i++;
      }
    }
  }
  else{
    if ((v[0] % 2) == 1)
    { // first element is odd;
      int i = 1, j = 1;
      while (i < n)
      {
        if (i % 2==0)
        {
          j = i;
          while (j < n && (v[j] % 2) == 0)
          {
            j++;
          }
          ans += j - i;
          swap(v[j], v[i]);
          i++;
        }
        else
        {
          j = i;
          while (j < n && (v[j] % 2) == 1)
          {
            j++;
          }
          ans += j - i;
          swap(v[j], v[i]);
          i++;
        }
      }
    }
    else
    { // first element is even

      int i = 1, j = 1;
      while (i < n)
      {
        if ((i % 2) == 1)
        {
          j = i;
          while (j < n && (v[j] % 2) == 0)
          {
            j++;
          }
          ans += j - i;
          swap(v[j], v[i]);
          i++;
        }
        else
        {
          j = i;
          while (j < n && (v[j] % 2)==1)
          {
            j++;
          }
          ans += j - i;
          swap(v[j], v[i]);
          i++;
        }
      }
    }
  }
  
  cout << ans << endl;
}


signed main()
{
  // fastio;
  int tc=1;
  cin>>tc;
  while(tc--){
    solve();
  }

  return 0;
}

