//Abhinav Singh
#include <bits/stdc++.h>
using namespace std;

const int N=510, inf=1e9+10;
int dx[8] = {-1, -1, 1, 1, 1, 0, -1, 0};
int dy[8] = {1, -1, 1, -1, 0, 1, 0, -1};
int g[N][N];
int vis[N][N];
int lvl[N][N];


int n,m,mx;
bool isValid(int x, int y){
  return (x>=1 and x<=n and y>=1 and y<=m and vis[x][y]==0);
}
int bfs(){
  queue<pair<int, int>> q;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(g[i][j]==mx){
        q.push({i,j});
        vis[i][j]=1;
        lvl[i][j]=0;
      }
    }
  }
  int ans=0;
  while(!q.empty()){
    auto p=q.front();
    int x=p.first;
    int y=p.second;
    q.pop();
    for(int i=0;i<8;i++){
      int childx=x+dx[i];
      int childy=y+dy[i];
      if(!isValid(childx,childy)) continue;
      q.push({childx,childy});
      vis[childx][childy]=1;
      lvl[childx][childy]=lvl[x][y]+1;
      ans = max(ans, lvl[childx][childy]);
    }
  }
  return ans;
}

void solve(){
  cin>>n>>m;
  mx=INT32_MIN;
  int cnt=0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>g[i][j];
      vis[i][j]=0;
      lvl[i][j]=inf;
      mx=max(mx,g[i][j]);
    }
  }
  
  cout<<bfs()<<endl;
}


signed main()
{
  int tc=1;
  cin>>tc;
  for(int testcase=1;testcase<=tc;testcase++){
    solve();
  }

  return 0;
}