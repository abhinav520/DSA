#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 	//pbds
//pbds ordered_set (similar to set) plus *s.find_by_order(x) & s.order_of_key(x)
#include <ext/pb_ds/tree_policy.hpp> 	//pbds
using namespace __gnu_pbds;

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x) 		cout << #x << "=" << x << endl
#define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec) 	for(int i=0;i<vec.size();i++){ cout<<vec[i]<<" ";} cout<<endl
#define input(vec,n) 	for(int i=0;i<n;i++){cin>>vec[i];}
#define sp(x,y) 	fixed<<setprecision(y)<<x
#define inf			1e18
#define PI 			3.1415926535897932384626
#define endl		"\n"
#define fastio 		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define watch 		srand(chrono::high_resolution_clock::now().time_since_epoch().count())
#define setbits(x)  __builtin_popcountll(x) // returns number of 1-bits of x
#define zerobits(x) __builtin_ctzll(x) //returns num of trailing 0-bits of x which starts from least significant bit position
//__builtin_clz(x) returns num of leading 0-bits of x which starts from most significant bit position
//__builtin_ffs(x) returns 1 + least significant 1-bit of x. can be suffixed with l(long) and ll(long long)
const int mod=1e9+7;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim){
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef long long int ll;
//--------------------------------------------------------------------------------------------

ll gcd(ll a, ll b)
{
  if (b > a)
  {
    return gcd(b, a);
  }
  if (b == 0)
  {
    return a;
  }
  return gcd(b, a % b);
}
ll expo(ll a, ll b, ll mod )
{
  ll res = 1;
  while (b > 0)
  {
    if (b & 1)
      res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
void extendgcd(ll a, ll b, ll *v)
{
  if (b == 0)
  {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  ll x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
  return;
} // pass an arry of size1 3
ll mminv(ll a, ll b)
{
  ll arr[3];
  extendgcd(a, b, arr);
  return arr[0];
} // for non prime b
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
void swap(int &x, int &y)
{
  int temp = x;
  x = y;
  y = temp;
}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact)
{
  ll val1 = fact[n];
  ll val2 = ifact[n - r];
  ll val3 = ifact[r];
  return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case #" << t << ": "; }
vector<ll> sieve(int n)
{
  int *arr = new int[n + 1]();
  vector<ll> vect;
  for (int i = 2; i <= n; i++)
    if (arr[i] == 0)
    {
      vect.push_back(i);
      for (int j = 2 * i; j <= n; j += i)
        arr[j] = 1;
    }
  return vect;
}
ll mod_add(ll a, ll b, ll m)
{
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
  a = a % m;
  b = b % m;
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m
ll phin(ll n)
{
  ll number = n;
  if (n % 2 == 0)
  {
    number /= 2;
    while (n % 2 == 0)
      n /= 2;
  }
  for (ll i = 3; i <= sqrt(n); i += 2)
  {
    if (n % i == 0)
    {
      while (n % i == 0)
        n /= i;
      number = (number / i * (i - 1));
    }
  }
  if (n > 1)
    number = (number / n * (n - 1));
  return number;
} // O(sqrt(N))


void solve()
{
  int a=10;

  cout << phin(10);
}


int main()
{
  fastio;
  watch;
  #ifndef ONLINE_JUDGE
  freopen("in3.txt", "r", stdin);
  freopen("in1.txt", "w", stdout);
  #endif

  int tc=1;
  cin>>tc;

  while(tc--){
    solve();
  }

  return 0;
}