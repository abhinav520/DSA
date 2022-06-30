#include <iostream>
#include <cstring>
using namespace std;
int dp[1001][10001];

int lcsRec(string s1, string s2, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }
    else if (s1[n - 1] == s2[m - 1])
    {
        return 1 + lcsRec(s1, s2, n - 1, m - 1);
    }
    else
    {
        return max(lcsRec(s1, s2, n, m - 1), lcsRec(s1, s2, n - 1, m));
    }
}

int lcsMemoi(string s1, string s2, int n, int m)
{
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    else
    {
        if (n == 0 || m == 0)
        {
            return dp[n][m] = 0;
        }
        else if (s1[n - 1] == s2[m - 1])
        {
            return dp[n][m] = 1 + lcsRec(s1, s2, n - 1, m - 1);
        }
        else
        {
            return dp[n][m] = max(lcsRec(s1, s2, n, m - 1), lcsRec(s1, s2, n - 1, m));
        }
    }
}

int lcsDp(string s1, string s2, int n, int m)
{
    string s="";
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                s+=s1[i-1];
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<s<<endl;
    return dp[n][m];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n, m;
    n = s1.length();
    m = s2.length();
    memset(dp, -1, sizeof(dp));
    cout<<"By Recursion-> "<<lcsRec(s1,s2,n,m)<<endl;
    cout<<"By Memoization-> "<<lcsMemoi(s1,s2,n,m)<<endl;
    cout<<"By top down(tabular)-> "<<lcsDp(s1,s2,n,m)<<endl;
    return 0;
}