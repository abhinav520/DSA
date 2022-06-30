#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(0), cin.tie(0)
#define all(x) x.begin(),x.end()
typedef long long ll;

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

int n,m;
vector<int> cycle;
bool dfs(vector<vector<int>> &g, vector<bool> &vis, vector<bool> &instk, int vertex)
{
  vis[vertex]=true;
  instk[vertex]=true;
  for(int child: g[vertex]){
    if(instk[child]){
      dbg(vertex,child);
      instk[vertex]=false;
      // instk[child]=false;
      cycle.push_back(vertex);  //start cycle
      return true;
    }
    else if(!vis[child]){
      if (dfs(g,vis,instk,child))
      {
        if(instk[vertex]){   //continue cycle
          cycle.push_back(vertex);
          dbg(vertex);
          instk[vertex]=false;
          return true;
        }
        else{  //found again
          cycle.push_back(vertex);
          return false;
        }
      }
      if (!cycle.empty()) // finished with cycle
        return false;
    }
  }
  instk[vertex]=false;
  return false;
}
int main()
{
  fastio;
  cin>>n>>m;
  vector<vector<int>> g(n+1);
  int edges=m; //chk this
  while(edges--){
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
  }
  vector<bool> vis(n+1,false);
  vector<bool> instk(n+1,false);
  dbg(g,vis,instk);
  for(int i=1;i<=n and cycle.empty();i++){
    dfs(g,vis,instk,i);
  }
    dbg(cycle, instk,vis);
  if(cycle.empty()){
    cout<<"IMPOSSIBLE\n";
  }
  else{
    reverse(all(cycle));
    cout<<cycle.size()+1<<endl;
    cout<<cycle.back()<<" ";
    for(auto &x:cycle){
      cout<<x<<" ";
    }
    cout<<endl;
  }
  return 0;
}