// Abhinav Singh
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ini(_n) \
  int _n;       \
  cin >> _n;
#define input(vec, s, n)          \
  vector<int> vec(s + n);         \
  for (int i = s; i < s + n; i++) \
  {                               \
    cin >> vec[i];                \
  }
#define output(vec, s, n)         \
  for (int i = s; i < s + n; i++) \
  {                               \
    cout << vec[i] << " ";        \
  }                               \
  cout << endl
#define inpu(vec)      \
  for (auto &el : vec) \
    cin >> el;
#define fill(v, p) memset(v, p, sizeof(v))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) ((int)(x).size())
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<pi> vpi;
typedef set<int> si;
typedef set<char> sc;
typedef set<pi> spi;
typedef multiset<int> mst;
typedef map<int, int> mi;
typedef map<char, int> mc;
typedef unordered_map<int, int> umi;
typedef unordered_map<char, int> umc;

#define setbits(x) __builtin_popcountll(x) // returns number of 1-bits of x
#define trailing0(x) __builtin_ctzll(x)    // returns num of trailing 0-bits of x
#define leading0(x) __builtin_clz(x)       // returns num of leading 0-bits of x
#define firstbitpos(x) __builtin_ffs(x)    // returns 1 + indexOf(least significant 1-bit)
#define binary(n) bitset<32>(n)
#define seal(n) (n & 1) ? (n / 2 + 1) : (n / 2)
const int mod = 1000000007;
const int mod2 = 998244353;
// functions
int mpow(int base, int exp)
{
  int ans = 1;
  while (exp)
  {
    if (exp & 1)
      ans = (ans * 1LL * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return ans;
}
vector<int> sieve(int n)
{
  int *arr = new int[n + 1]();
  vector<int> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0)
    {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i)
        arr[j] = 1;
    }
  return vect;
}

/******************************************************************************************************************************************************/

void solve()
{
  ini(a);
  ini(s);

  string aa = to_string(a);
  string ss = to_string(s);
  int j = sz(aa) - 1;
  int i = sz(ss) - 1;
  int b = 0;
  int mult = 1;
  while (i >= 0 and j >= 0)
  {
    int f = ss[i--] - '0';
    int g = aa[j--] - '0';

    if (f < g)
    {
      if((int)(ss[i]-'0')>1){
        cout<<-1<<endl;
        return;
      }
      f = (int)(ss[i] - '0') * 10 + f;
      if(f<g){
        cout << -1 << endl;
        return;
      }
      i--;
    }
    // dbg(f, g);
    b = (f - g) * mult + b;
    // dbg(b, i, j);
    mult *= 10;
  }
  while (i >= 0)
  {
    b = (ss[i--] - '0') * mult + b;
    mult*=10;  //why i missed this
  }
  if (j >= 0)
  {
    cout << -1 << endl;
    return;
  }
  cout << b << endl;
}

signed main()
{
  // fastio;
  int tc = 1;
  cin >> tc;
  while (tc--)
  {
    solve();
  }

  return 0;
}