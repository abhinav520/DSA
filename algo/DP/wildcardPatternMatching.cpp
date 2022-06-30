#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int arr[201][201];
    int MemoizeSolve(string &ptrn,string &s,int n,int m)
    {
        if(n==0 && m==0) return 1;
        if(m==0) return 0;
        if(n==0){
            for(int i=0;i<m;i++){
                if(ptrn[i]!='*')
                    return 0;
            }
            return 1;
        }
        if(arr[n][m]!=-1) return arr[n][m]; 
        if(ptrn[m-1]=='*'){
            if(arr[n-1][m-1]==-1) arr[n-1][m-1]=MemoizeSolve(ptrn,s,n-1,m-1); 
            if(arr[n-1][m]==-1) arr[n-1][m]=MemoizeSolve(ptrn,s,n-1,m); 
            if(arr[n][m-1]==-1) arr[n][m-1]=MemoizeSolve(ptrn,s,n,m-1); 
            return arr[n][m]=max(arr[n-1][m-1],max(arr[n-1][m],arr[n][m-1]));
        }
        if(ptrn[m-1]=='?' || ptrn[m-1]==s[n-1]){
            return arr[n][m]=MemoizeSolve(ptrn,s,n-1,m-1);
        }
        return arr[n][m]=0;
    }



    bool RecursiveSol(string &ptrn, string &s, int n, int m)
    {
        if (n == 0 && m == 0)
            return true;
        if (m == 0)
            return false;
        if (n == 0)
        {
            for (int i = 0; i < m; i++)
            {
                if (ptrn[i] != '*')
                    return false;
            }
        }
        if (ptrn[m - 1] == '*')
        {
            return RecursiveSol(ptrn, s, n - 1, m - 1) || RecursiveSol(ptrn, s, n - 1, m) || RecursiveSol(ptrn, s, n, m - 1);
        }
        if (ptrn[m - 1] == '?' || ptrn[m - 1] == s[n - 1])
        {
            return RecursiveSol(ptrn, s, n - 1, m - 1);
        }
        return false;
    }

    int wildCard(string ptrn, string s)
    {
        int n = s.length();
        int m = ptrn.length();
        memset(arr,-1,sizeof(arr));
        // if(solve(ptrn,s,n,m)) return 1;
        // if (RecursiveSol(ptrn, s, n, m))
        //     return 1;
        // return 0;
        bool dp[n+1][m+1];
        memset(dp,false,sizeof(dp));
        dp[0][0]=true;
        for(int j=1;j<=m;j++){
            if(ptrn[j-1]=='*'){
                dp[0][j]=dp[0][j-1];
            }
        }
        for(int i=i;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(ptrn[j-1]=='*'){
                    dp[i][j]=dp[i][j-1]||dp[i-1][j]||dp[i][j-1];
                }
                else if(ptrn[j-1]=='?' || ptrn[j-1]==s[i-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                    dp[i][j]=false;
            }
        }
        dp[n][m];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  //1 <= length of(str,pat) <= 200
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
    return 0;
}