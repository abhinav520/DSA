//Maxflow
//https://cses.fi/problemset/task/1694/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF =1e18;

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

//Time complexity O(vE^2)
//Edmonds-Karp algorithm

int n,m;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int> &parent)
{
  fill(parent.begin(), parent.end(), -1);
  parent[s] = -2;
  queue<pair<int, int>> q;
  q.push({s, INF});

  while (!q.empty())
  {
    int cur = q.front().first;
    int flow = q.front().second;
    q.pop();

    for (int next : adj[cur])
    {
      if (parent[next] == -1 && capacity[cur][next])
      {
        parent[next] = cur;
        int new_flow = min(flow, capacity[cur][next]);
        if (next == t)
          return new_flow;
        q.push({next, new_flow});
      }
    }
  }

  return 0LL;
}

int maxflow(int s, int t)
{
  int flow = 0;
  vector<int> parent(n);
  int new_flow;

  while ((new_flow = bfs(s, t, parent)))
  {
    flow += new_flow;
    dbg(flow,new_flow);
    int cur = t;
    while (cur != s)
    {
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
    // dbg(capacity);
  }

  return flow;
}

signed main()
{
  cin>>n>>m;
  capacity.resize(n,vector<int> (n));
  adj.resize(n);
  for(int i=0;i<m;i++){
    int u,v,cost;
    cin>>u>>v>>cost;
    u--;v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    capacity[u][v]+=cost;  //between two computer if there are more than one cabel
    capacity[v][u]+=0;
  }
  for(auto &x:adj){
    sort(begin(x),end(x)), x.erase(unique(begin(x),end(x)), x.end());
    //between two computer if there are more than one cabel
    dbg(x);
  }
  dbg(adj);
  dbg(capacity);
  cout<<maxflow(0,n-1)*1LL<<endl;
  return 0;
}