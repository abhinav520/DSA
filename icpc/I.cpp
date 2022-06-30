
bool dfs(int s, int parent, vector<int> adj[], vector<int> vis, vector<int> cnt)
{
  vis[s] = 1;
  for (auto x : adj[s])
  {
    if (vis[x] == 0)
    {
      if (dfs(x, s, adj, vis, cnt))
        return true;
    }
    else if (x != parent)
      return true;
  }
  return false;
}
bool isCycle(int src, int V, vector<int> adj[], vector<int> cnt)
{
  bool ans = false;
  vector<int> vis(V);
  for (int i = src; i < V; i++)
  {
    if (vis[i] == 0)
    {
      ans = dfs(i, -1, adj, vis, cnt);
      if (ans)
        return true;
    }
  }
  return false;
}