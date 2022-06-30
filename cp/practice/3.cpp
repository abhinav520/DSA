#include <bits/stdc++.h>
using namespace std;

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define deb(x) cout << #x << "=" << x << endl //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec, s, n)         \
  for (int i = s; i < s + n; i++) \
  {                               \
    cout << vec[i] << " ";        \
  }                               \
  cout << endl
#define input(vec, s, n)          \
  vector<int> vec(s + n);         \
  for (int i = s; i < s + n; i++) \
  {                               \
    cin >> vec[i];                \
  }
// #define input(vec) for (auto &el : vec) cin >> el;
#define print(vec)     \
  for (auto &el : vec) \
    cout << el << " "; \
  cout << '\n';
#define fill(v, p) memset(v, p, sizeof(v))
#define all(v) v.begin(), v.end()
#define ini(_n) \
  int _n;       \
  cin >> _n;
#define inl(_n) \
  ll _n;        \
  cin >> _n;
#define go   \
  int tc;    \
  cin >> tc; \
  while (tc--)
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;

void solve()
{
  ini(n);
  ini(m);
  vector<int> a(n, 0), b(m, 0);
  bool f1=false,f2=false;
  ini(p);
  while (p--)
  {
    ini(t);
    a[t % n] = 1;
    b[t % m] = 1;
  }
  ini(q);
  while (q--)
  {
    ini(t);
    a[t % n] = 1;
    b[t % m] = 1;
  }
  int gh=1000000;
  int i=0;
  while(gh--){
    a[i%n]=max(a[i%n],b[i%m]);
    b[i%m]=max(a[i%n],b[i%m]);
    i++;
  }
  for(int i=0;i<n;i++){
    if(a[i]==0){
      cout<<"No\n";
      return;
    }
  }
  for(int i=0;i<m;i++){
    if(b[i]==0){
      cout<<"No\n";
      return;
    }
  }
  if((n+m)&1){
    cout<<"Yes\n";
    return;
  }
  int od1=0;
  int ev1=0;
  int od2=0;
  int ev2=0;
  for(int i=0;i<n;i++){
    if(i&1){
      if(a[i]==1){
        od1++;
      }
    }
    else{
       if(a[i]==1){
        ev1++;
      }
    }
  }
  for(int i=0;i<m;i++){
    if(i&1){
      if(b[i]==1){
        od2++;
      }
    }
    else{
       if(b[i]==1){
        ev2++;
      }
    }
  }
  if((ev1 ==0 && ev2==0) || (od1==0 && od2==0)){
    cout<<"No\n";
    return;
  }
  cout << "Yes\n";
}

int main()
{
  fastio;
  // go{
  solve();
  // }
  return 0;
}