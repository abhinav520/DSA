#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> g[N];
bool vis[N];

void dfs(int vertex){

  //Take action on vertex after entering the vertex

  // if(vis[vertex]) return;
  vis[vertex]=true;

  for(int child: g[vertex]){
    //Take action on child before entering the child node
    if(vis[child]) continue;
    cout<<vertex<<" "<<child<<endl;
    dfs(child);
    //Take action on child after entering the child node
  }

  //Take action on vertex before leaving the vertex
}

int main()
{
  int n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(0);
  return 0;
}