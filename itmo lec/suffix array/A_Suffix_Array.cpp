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

void count_sort(vector<int> &p, vector<int> &c){
  int n=p.size();
  vector<int> cnt(n);
  for(auto &x:c){
    cnt[x]++;
  }
  vector<int> pos(n);
  pos[0]=0;
  for(int i=1;i<n;i++){
    pos[i]=pos[i-1]+cnt[i-1];
    pos[i]++;
  }
  vector<int> p_new(n);
  for(auto &x: p){
    int i=c[x];
    p_new[pos[i]]=x;
    pos[i]++;
  }
  p=p_new;
}

int main()
{
  fastio;
  string str;
  cin>>str;
  str+='$';
  int n=str.size();
  vector<int> s(n);  // index i represent string starting from that index to (index+len)mod n
  vector<int> p(n);
  vector<pair<int, int>> vv;
  for(int i=0;i<n;i++){
    vv.emplace_back(str[i],i);
  }
  sort(all(vv));
  int c=0;
  s[vv[0].second]=c;
  for(int i=1;i<n;i++){
    if(vv[i-1].first<vv[i].first) c++;
    s[vv[i].second]=c;
  }
  for(int i=0;i<n;i++){
    p[i]=vv[i].second;
  }
  dbg(p);
  dbg(s);
  int i=0;
  while((1<<i)){
    for(int j=0;j<n;j++){
      p[j]=(p[j]- (1<<i) +n)%n;  //shifting by (1<<i) 2^i 
    }
    count_sort(p,s);
    vector<int> s_new(n);
    for(int j=0;j<n;j++){
      pair<int,int> prev={s[p[j-1]],s[(p[j-1]+(1<<i))%n]};
      pair<int,int> now={s[p[j]],s[(p[j]+(1<<i))%n]};
      s_new[p[j]]=s_new[p[j]-1];
      if(prev!=now){
        s_new[p[j]]+=1;
      }
    }
    i++;
  }
  dbg(s);
  for(int i=0;i<n;i++){
    cout<<p[i];
    cout<<" "<<str.substr(p[i],n-p[i])<<"\n";
  }
  return 0;
}