#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define all(v) v.begin(), v.end()
#define endl '\n'
#define int int64_t
#define MAXN (int)1e6+10           //biggest possible array length
#define K 25                
int st[MAXN][K + 1];
int N;
int lg[MAXN + 1];

int f(int x, int y){
  return min(x,y);
}
void precompute(vector<int> &array){
  for (int i = 0; i < N; i++)
    st[i][0] = (array[i]);

  for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= N; i++)
      st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
signed main()
{
  fastio;
  cin>>N;
  vector<int> array(N);
  for(auto &x:array) cin>>x;
  lg[1] = 0;
  for (int i = 2; i <= MAXN; i++)
    lg[i] = lg[i / 2] + 1;
  precompute(array);
  int Q;
  cin>>Q;
  while(Q--){
    int L,R;
    cin>>L>>R;
    int j = lg[R - L + 1];
    int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
    cout<<minimum<<endl;
  }
  return 0;
}

