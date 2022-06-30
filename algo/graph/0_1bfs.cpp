// https://www.codechef.com/problems/REVERSE
//In nutshell
//O-1 bfs is used to find shortest path when weight of edges is either 0 or 1, (although this can be find out by dijekstra but it runs in O(|E|logV) wheras it can find in O(|E|)) 
//We maintain lvl array lvl (info about dis from source) if edge is 0 we consider it in the same lvl and push in front of queue else when edge is 1 we treat like normal bfs ie push in back of queue;
//key obs - lvl of particular edge can be changed atmost 2, first via edge of weight 1 and second via edge of weight 0
//here lvl also works as vis array

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
const int N = 1e5 + 6;
const int inf = 1e9 + 6;

int n, m;
vector<pair<int, int>> g[N];
vector<int> lvl(N, inf);

int bfs()
{
  deque<int> dq;
  dq.push_back(1);
  lvl[1] = 0;
  while (!dq.empty())
  {
    int parent = dq.front();
    dq.pop_front();
    for (auto p : g[parent])
    {
      int child = p.first;
      int wt = p.second;
      if (lvl[parent] + wt < lvl[child])
      {
        lvl[child] = lvl[parent] + wt;
        if (wt == 1)
        {
          dq.push_back(child);
        }
        else
          dq.push_front(child);
      }
    }
  }
  return lvl[n] == inf ? -1 : lvl[n];
}

void solve()
{
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    if (x == y)
      continue;
    g[x].push_back({y, 0});
    g[y].push_back({x, 1});
  }

  cout << bfs() << endl;
}

signed main()
{
  fastio;
  int tc = 1;
  // cin>>tc;
  for (int testcase = 1; testcase <= tc; testcase++)
  {
    // dbg(testcase);
    solve();
  }

  return 0;
}