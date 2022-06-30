#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(0), cin.tie(0)
typedef long long ll;
#define all(x) begin(x), end(x)

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

void radix_sort(vector<pair<pair<int,int>,int>> &p){
  int n=p.size();
  vector<pair<pair<int,int>,int>> p_new(n);
  {
    vector<int> cnt(n);
    for(auto &x:p){
      cnt[x.first.second]++;
    }
    vector<int> pos(n);
    pos[0]=0;
    for(int i=1;i<n;i++){
      pos[i]=pos[i-1]+cnt[i-1];
    }
    for(auto &x:p){
      int i = x.first.second;
      p_new[pos[i]] = x;
      pos[i]++;
    }
    p=p_new;
  }
  {
    vector<int> cnt(n);
    for(auto &x:p){
      cnt[x.first.first]++;
    }
    vector<int> pos(n);
    pos[0]=0;
    for(int i=1;i<n;i++){
      pos[i]=pos[i-1]+cnt[i-1];

    }
    for(auto &x:p){
      int i=x.first.first;
      p_new[pos[i]]=x;
      pos[i]++;
    }
    p=p_new;
  }
}
int main()
{
  fastio;
  string str;
  cin>>str;
  str+='$';
  int n=str.size();
  vector<int> s(n);  // index i represent string starting from that index to (index+len)mod n
  vector<pair<int, int>> p;
  for(int i=0;i<n;i++){
    p.emplace_back(str[i],i);
  }
  sort(all(p));
  int c=0;
  s[p[0].second]=c;
  for(int i=1;i<n;i++){
    if(p[i-1].first<p[i].first) c++;
    s[p[i].second]=c;
  }
  p.clear();
  int i=0;
  while((1<<i)){
    vector<pair<pair<int,int>,int>> p(n);
    for(int j=0;j<n;j++){
      p[j]={{s[j],s[(j+(1<<i))%n]},j};
    }
    radix_sort(p);
    dbg(p);
    int c=0;
    s[p[0].second] = c;
    for (int j = 1; j < n;j++)
    {
      if (p[j - 1].first < p[j].first)
        c++;
      s[p[j].second] = c;
    }
    dbg(s);
    if(c==n-1 or i>n) break;
    // p.clear();
    i++;
  }
  dbg(s);
  p.clear();
  for(int i=0;i<n;i++){
    p.emplace_back(s[i],i);
  }
  sort(all(p));
  for(auto &x: p){
    cout<<x.second<<" ";
  }
  cout<<endl;
  return 0;
}