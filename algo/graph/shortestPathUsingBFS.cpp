// https://www.spoj.com/problems/NAKANJ/

//When edges of graph is same bfs can be used to find shortes path b/w source and destination in O(|E|)
#include <bits/stdc++.h>
using namespace std;

const int INF = -1;
int lvl[8][8];
int vis[8][8];

int rx[8] = {-1, -1, 1, 1, 2, 2, -2, -2};
int cy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

bool isValid(int x, int y)
{
  return (x >= 0 and x < 8 and y >= 0 and y < 8 and vis[x][y] == 0);
}
int bfs(string &s, string &d)
{
  int sx = s[0] - 'a';
  int sy = s[1] - '1';
  int dx = d[0] - 'a';
  int dy = d[1] - '1';
  lvl[sx][sy] = 0;
  // dbg(sx,sy,dx,dy);
  queue<pair<int, int>> q;
  q.push({sx, sy});
  vis[sx][sy] = 1;
  while (!q.empty())
  {
    auto p = q.front();
    q.pop();
    int x = p.first, y = p.second;
    for (int i = 0; i < 8; i++)
    {
      int childx = x + rx[i];
      int childy = y + cy[i];
      if (!isValid(childx, childy))
        continue;
      // dbg(x,y,childx,childy);
      q.push({childx, childy});
      vis[childx][childy] = 1;
      lvl[childx][childy] = lvl[x][y] + 1;
      // dbg(lvl[childx][childy],lvl[x][y]);
    }

    if (lvl[dx][dy] != -1)
    {
      return lvl[dx][dy];
    }
  }
  return lvl[dx][dy];
}

void solve()
{
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      lvl[i][j] = -1;
      vis[i][j] = 0;
    }
  }
  string src;
  cin >> src;
  string des;
  cin >> des;
  cout << bfs(src, des) << endl;
}

signed main()
{
  // fastio;
  int tc = 1;
  cin >> tc;
  for (int testcase = 1; testcase <= tc; testcase++)
  {
    // dbg(testcase);
    solve();
  }

  return 0;
}