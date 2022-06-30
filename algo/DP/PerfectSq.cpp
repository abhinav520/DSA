#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSquares(int n)
    {
        static int dp[10002];
        memset(dp,INT_MAX,sizeof(dp));
        dp[0] = 0;
        if (dp[n] != 0)
        {
            return dp[n];
        }
        if (n == 0)
        {
            return 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
        return dp[n];
    }
};
int main()
{
    Solution ob;
    int n;
    cin >> n;
    cout << ob.numSquares(n);
    return 0;
}


