#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
char c[9]={'x','c','h','o','k','u','d','a','i'};
const int m=1e9+7;


int solve(string &s,int n){
    ll dp[n+1][9];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=8;j++){
            if(s[i-1]==c[j]){
                dp[i][j]=(dp[i-1][j-1]%m+dp[i-1][j]%m)%m;
            }
            else{
                dp[i][j]=dp[i-1][j]%m;
            }
        }
    }
    return dp[n][8]%m;

}

int main()
{
    string s;cin>>s;
    cout<<solve(s,s.size());
    return 0;
}