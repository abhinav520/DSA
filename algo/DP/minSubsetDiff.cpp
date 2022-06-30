#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int solve(vector<int> &A);
};
int Solution::solve(vector<int> &A) {
    int sum=0;
    for(int x:A){
        sum+=x;
    }
 
    int n=A.size();
    int dp[n+1][sum+1];
    memset(dp,0,sizeof(dp));
    for(int l=0;l<n+1;l++){
        dp[l][0]=1;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(A[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=(dp[i-1][j-A[i-1]]||dp[i-1][j]);
            }
        }
    }
    set<int> s;
    for(int i=0;i<=sum/2;i++){
        if(dp[n][i]){
            s.insert((sum-2*i));
        }
    }
    auto it=s.begin();
    return *it;
}
int main()
{
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0; i<n;i++){
        cin>>A[i];
    }
    Solution ob;
    cout<<ob.solve(A);
    return 0;
}