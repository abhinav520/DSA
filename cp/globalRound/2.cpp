#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(0), cin.tie(0)
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

int n, m;
void dfs(vector<vector<int>> &g, vector<int> &vis, int vertex, stack<int> &stk)
{
  //Take action on vertex after entering the vertex

  // if(vis[vertex]) return;
  vis[vertex]=true;

  for(int child: g[vertex]){
    //Take action on child before entering the child node
    if(vis[child]) continue;
    //cout<<vertex<<" "<<child<<endl;
    dfs(g, vis, child, stk);
    //Take action on child after entering the child node
  }
    stk.push(vertex);

  //Take action on vertex before leaving the vertex
}

void topological_sort(vector<vector<int>> &g)
{
  vector<int> vis(n+1,0);
  stack<int> stk;
  for(int i=1;i<=n;i++){
    if(vis[i]==0){
      dfs(g,vis,i,stk);
    }
  }
  vector<int> top_sort_list;
  while(!stk.empty()){
    cout<<stk.top()<<" ";
    top_sort_list.emplace_back(stk.top());
    stk.pop();
  }
  dbg(top_sort_list,vis);
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
  dbg(g);
  topological_sort(g);
  cout<<endl;
  return 0;
}