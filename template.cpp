#include <bits/stdc++.h>
using namespace std;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define endl "\n"
#define YES cout << "YES" \
                 << "\n";
#define NO cout << "NO" \
                << "\n";
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pl;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}
ll mpow(ll base, ll exp);
void ipgraph(ll n, ll m);
void dfs(ll u, ll par);

const ll mod = 1'000'000'007;
const ll N = 3e5, M = N;
//=======================

//--------------------debugTemplate-------------------------//
bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << '(' << p.first << ', ' << p.second << ')' : os << p.first << ' ' << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << '['; for (const T &x : v) { if (f) os << ', '; os << x; f = true; } os << ']'; } else { for (const T &x : v) { if (f) os << ' '; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << '\n'; } template <typename Head> void print(const Head &H) { cout << H << '\n'; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << ' '; print(T...); }
template <typename Head> void dbg_out(string var, const Head &H) { cerr << var << ' = ' << H << endl; } template <typename Head, typename ...Tail> void dbg_out(string var, const Head &H, const Tail &...T) { for (int i = 0, b = 0; i < int(var.size()); i++) { if (var[i] == '(' || var[i] == '{') { b++; } else if (var[i] == ')' || var[i] == '}') { b--; } else if (var[i] == ',' && b == 0) { cerr << var.substr(0, i) << ' = ' << H << ' | '; dbg_out(var.substr(var.find_first_not_of(' ', i + 1)), T...); break; } } }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; }
template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }
#ifndef ONLINE_JUDGE
#define dbg(...) debug = true, dbg_out(#__VA_ARGS__, __VA_ARGS__), debug = false
#else
#define dbg(...)
#endif
//--------------------debugTemplate-------------------------//

vi g[N];
ll a[N];

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void prifac(ll N)  //give power of primes of num (24=1:1,2:3,3:1)
{
    ll i;
    unordered_map<ll, ll, custom_hash> fac;
    fac[1] = 1;
    for (i = 2; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            ll c = 0;
            while (N % i == 0)
                c++, N /= i;
            fac[i] = c;
        }
    }
    if (N > 1)
        fac[N] = 1;
}

ll gcd(ll a, ll b){
    if(b==0) return a;     //gcd(r,0)=r; (Euclidean algo)        
    return gcd(b,a%b);    //gcd(a,b)=gcd(b,remainder)
}

vl prime;
void SieveOfEratosthenes(ll n)
{
    bool prm[n + 1];
    memset(prm, true, sizeof(prm));

    for (ll p = 2; p * p <= n; p++)
        if (prm[p] == true)
            for (ll i = p * p; i <= n; i += p)
                prm[i] = false;

    for (ll p = 2; p <= n; p++)
        if (prm[p])
            prime.push_back(p);
    return;
}

ll isPerfectSquare(ll x)
{
    ll left = 1, right = x;

    while (left <= right)
    {
        ll mid = (left + right) / 2;

        // Check if mid is perfect square
        if (mid * mid == x)
        {
            return mid;
        }
        // Mid is small -> go right to increase mid
        if (mid * mid < x)
        {
            left = mid + 1;
        }
        // Mid is large -> to left to decrease mid
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

bool isPrime(ll n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

//----------------------------------------------------------------------------------------------------------------------------------//
void solve()
{
    string r_str =
    R"(Dear Programmers,
    I'm using C++11
    Regards, Swift!)";
    cout << r_str;
    cout<<3;
    deb(r_str);
    string str =
    "(Dear Programmers, I'm using C++11 Regards, Swift!)";
                cout << str;
    dbg(r_str);
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------//

ll mpow(ll base, ll exp)
{
    base %= mod;
    ll result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void ipgraph(ll n, ll m)
{
    ll i, u, v;
    while (m--)
    {
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
}

void dfs(ll u, ll par)
{
    for (ll v : g[u])
    {
        if (v == par)
            continue;
        dfs(v, u);
    }
}