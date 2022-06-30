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

template <typename T>
T inverse(T a, T m)
{
  T u = 0, v = 1;
  while (a != 0)
  {
    T t = m / a;
    m -= t * a;
    swap(a, m);
    u -= t * v;
    swap(u, v);
  }
  assert(m == 1);
  return u;
}
template <typename T>
class Modular
{
public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U &x)
  {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U &x)
  {
    Type v;
    if (-mod() <= x && x < mod())
      v = static_cast<Type>(x);
    else
      v = static_cast<Type>(x % mod());
    if (v < 0)
      v += mod();
    return v;
  }

  const Type &operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular &operator+=(const Modular &other)
  {
    if ((value += other.value) >= mod())
      value -= mod();
    return *this;
  }
  Modular &operator-=(const Modular &other)
  {
    if ((value -= other.value) < 0)
      value += mod();
    return *this;
  }
  template <typename U>
  Modular &operator+=(const U &other) { return *this += Modular(other); }
  template <typename U>
  Modular &operator-=(const U &other) { return *this -= Modular(other); }
  Modular &operator++() { return *this += 1; }
  Modular &operator--() { return *this -= 1; }
  Modular operator++(int32_t)
  {
    Modular result(*this);
    *this += 1;
    return result;
  }
  Modular operator--(int32_t)
  {
    Modular result(*this);
    *this -= 1;
    return result;
  }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int32_t>::value, Modular>::type &operator*=(const Modular &rhs)
  {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
        "divl %4; \n\t"
        : "=a"(d), "=d"(m)
        : "d"(xh), "a"(xl), "r"(mod()));
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type &operator*=(const Modular &rhs)
  {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type &operator*=(const Modular &rhs)
  {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular &operator/=(const Modular &other) { return *this *= Modular(inverse(other.value, mod())); }

  template <typename U>
  friend const Modular<U> &abs(const Modular<U> &v) { return v; }

  template <typename U>
  friend bool operator==(const Modular<U> &lhs, const Modular<U> &rhs);

  template <typename U>
  friend bool operator<(const Modular<U> &lhs, const Modular<U> &rhs);

  template <typename U>
  friend std::istream &operator>>(std::istream &stream, Modular<U> &number);

private:
  Type value;
};

template <typename T>
bool operator==(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value == rhs.value; }
template <typename T, typename U>
bool operator==(const Modular<T> &lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U>
bool operator==(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) == rhs; }

template <typename T>
bool operator!=(const Modular<T> &lhs, const Modular<T> &rhs) { return !(lhs == rhs); }
template <typename T, typename U>
bool operator!=(const Modular<T> &lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T> &rhs) { return !(lhs == rhs); }

template <typename T>
bool operator<(const Modular<T> &lhs, const Modular<T> &rhs) { return lhs.value < rhs.value; }

template <typename T>
Modular<T> operator+(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U>
Modular<T> operator+(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) += rhs; }

template <typename T>
Modular<T> operator-(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U>
Modular<T> operator-(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T>
Modular<T> operator*(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U>
Modular<T> operator*(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T>
Modular<T> operator/(const Modular<T> &lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U>
Modular<T> operator/(const Modular<T> &lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T> &rhs) { return Modular<T>(lhs) /= rhs; }

template <typename T, typename U>
Modular<T> power(const Modular<T> &a, const U &b)
{
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0)
  {
    if (p & 1)
      res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template <typename T>
bool IsZero(const Modular<T> &number)
{
  return number() == 0;
}

template <typename T>
string to_string(const Modular<T> &number)
{
  return to_string(number());
}

template <typename T>
std::ostream &operator<<(std::ostream &stream, const Modular<T> &number)
{
  return stream << number();
}

template <typename T>
std::istream &operator>>(std::istream &stream, Modular<T> &number)
{
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

/*
using ModType = int32_t;

struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/

constexpr int32_t md = 998244353;
// constexpr int32_t md = 1000000007;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
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
vector<Mint> fact(1001);

void solve(){
  ini(n);
  if(n%2==1){
    cout<<0<<endl;
    return;
  }
  n/=2;
  Mint ans=fact[n]*fact[n];
  cout<<ans<<endl;
}


signed main()
{
  fastio;
  int tc=1;
  fact[0]=1;
  fact[1]=1;
  Mint p=1;
  for(int i=2;i<=1000;i++){
    p*=i;
    fact[i]=p;
  }
  cin>>tc;
  for(int testcase=1;testcase<=tc;testcase++){
    //dbg(testcase);
    solve();
  }

  return 0;
}