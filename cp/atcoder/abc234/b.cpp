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
#define mod			1'000'000'007;
#define PI 			3.1415926535897932384626
#define endl		"\n"
#define fastio 		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define watch 		srand(chrono::high_resolution_clock::now().time_since_epoch().count())
#define setbits(x)  __builtin_popcountll(x) // returns number of 1-bits of x
#define zerobits(x) __builtin_ctzll(x) //returns num of trailing 0-bits of x which starts from least significant bit position
//__builtin_clz(x) returns num of leading 0-bits of x which starts from most significant bit position
//__builtin_ffs(x) returns 1 + least significant 1-bit of x. can be suffixed with l(long) and ll(long long)

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim){
  uniform_int_distribution<int> uid(0, lim - 1);
  return uid(rang);
}
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef long long int ll;
//--------------------------------------------------------------------------------------------


void solve()
{
  int n, k;
  cin>>n>>k;
  vector<int> p(n+1);
  for(int i=1;i<=n;i++) cin>>p[i];
  // int mx=*max_element(begin(p)+1,begin(p)+1+k);
  pbds s;
  for (int i = 1; i <= k; i++)
  {
    s.insert(p[i]);
  }
  int j = 0;
  int mx = *s.find_by_order(k-1);
  // deb(mx);
  cout << mx << endl;
  for (int i = k + 1; i <= n; i++)
  {
    if (p[i] > mx)
    {
      s.insert(p[i]);
      mx = *s.find_by_order(k-1);
    }
    cout << mx << endl;
  }
}


int main()
{
  fastio;
  int tc=1;
  // cin>>tc;

  while(tc--){
    solve();
  }

  return 0;
}