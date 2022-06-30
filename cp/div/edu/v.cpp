// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  // Knight moves
  int dx[8] = {-2, -2, -1, 1, -1, 1, 2, 2};
  int dy[8] = {1, -1, -2, -2, 2, 2, -1, 1};
  bool vis[1001][1001];

public:
  // Function to find out minimum steps Knight needs to reach target position.
  bool isSafe(int x, int y, int n)
  {
    return (x >= 1 and y >= 1 and x <= n and y <= n and vis[x][y] == false);
  }
  int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
  {
    if (KnightPos[0] == TargetPos[0] and KnightPos[1] == TargetPos[1])
      return 0;
    for(int i=1;i<=N;i++){
      for(int j=1;j<=N;j++){
        vis[i][j]=false;
      }
    }
    queue<vector<int>> q;
    KnightPos.resize(3);
    KnightPos[2] = 0;

    q.push(KnightPos);
    int ans = 0;
    while (!q.empty())
    {
      vector<int> p = q.front();
      q.pop();
      int x = p[0];
      int y = p[1];
      ans = p[2];

      for (int i = 0; i < 8; i++)
      {
        if (isSafe(x + dx[i], y + dy[i], N))
        {
          vis[x][y] = true;
          if (x + dx[i] == TargetPos[0] and y + dy[i] == TargetPos[1])
          {

            return ans + 1;
          }
          vector<int> v = {x + dx[i], y + dy[i], ans + 1};
          q.push(v);
        }
      }
    }
    return -1;
  }
};

// { Driver Code Starts.
int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    vector<int> KnightPos(2);
    vector<int> TargetPos(2);
    int N;
    cin >> N;
    cin >> KnightPos[0] >> KnightPos[1];
    cin >> TargetPos[0] >> TargetPos[1];
    Solution obj;
    int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
    cout << ans << "\n";
  }
  return 0;
} // } Driver Code Ends