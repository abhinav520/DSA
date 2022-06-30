#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x)  cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y)  cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec,s,n)  for(int i=s;i<s+n;i++){ cout<<vec[i]<<" ";} cout<<endl
// #define input(vec,s,n) vector<int> vec(s+n);for(int i=s;i<s+n;i++){cin>>vec[i];}
#define input(vec) for (auto &el : vec) cin >> el;
#define print(vec) for (auto &el : vec) cout << el ; cout << '\n'; 
#define fill(v,p) memset(v,p,sizeof(v))
#define all(v) v.begin(),v.end()
#define ini(_n)  int _n;cin>>_n;
#define inl(_n) ll _n;cin>>_n;
#define go  int tc;cin>>tc;while(tc--)
#define endl '\n'
#define fastio  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;


void solve(){
  ini(n);
  ini(m);
  vector<vector<char>> grid(n, vector<char>(m));
  rep(i, 0, n)
  {
    input(grid[i]);
  }
  queue<pair<int,int>> q;
  rep(i,0,n){
    rep(j,0,m){
      if(grid[i][j]=='L'){
        // q.emplace(i-1,j);
        // q.emplace(i+1,j);
        // q.emplace(i,j-1);
        // q.emplace(i,j+1);
        q.push({i, j});
      }
    }
  }
  const int dr[] = {0, 0, -1, 1};
  const int dc[] = {-1, 1, 0, 0};
  auto isValid= [&](int x, int y){
    if (x >= n or y >= m or x < 0 or y < 0 or grid[x][y] != '.') 
      return false;
    return true;

  };
  int x,y;
  while(!q.empty()){
    x = q.front().first, y = q.front().second;
    q.pop();
    for(int dir=0;dir<4;dir++){
      int nx=x+dr[dir],ny=y+dc[dir];
      if(isValid(nx,ny)){
        int neigh=0,nr,nc;
        for(int ndir=0;ndir<4;ndir++){
          nr=nx+dr[ndir], nc=ny+dc[ndir];
          if(isValid(nr,nc)){
            neigh++;
            
          }

        }
        if (neigh < 2)
        {
          grid[nr][nc] = '+';
          q.emplace(nr, nc);
        }
      }
    }
    
  }
  rep(i,0,n){
    print(grid[i]);
  }
}


int main()
{
  // fastio;
  go{
    solve();
  }
  return 0;
}