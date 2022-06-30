//https://leetcode.com/problems/target-sum/
//You are given an integer array nums and an integer target. You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();

        int b[n];  //for handling case for 0es element
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                b[i]=1;
            }
        }

        for(int i=1;i<n;i++){
            b[i]=b[i-1]+b[i];
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int reducedSum=(target+sum);
        if(reducedSum%2!=0){
            return 0;
        }
        reducedSum/=2;
        int dp[n+1][reducedSum+1];
        dp[0][0]=1;
        int flag=0;
        for(int l=1;l<n+1;l++){
            dp[l][0]=1;
            if(nums[l-1]==0 || flag==1){
                flag=1;
                dp[l][0]=(int)pow(2,b[l-1]);
            }
        }
        for(int k=1;k<reducedSum+1;k++){
            dp[0][k]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<reducedSum+1;j++){
                if(nums[i-1]>j){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=(dp[i-1][j-nums[i-1]] + dp[i-1][j]);
                }
            }
        }
        return dp[n][reducedSum];
    }
};
int main()
{
    int n,target;
    
    // cin>>n>>target;
    vector<int> A(n);
    // for(int i=0; i<n;i++){
    //     cin>>A[i];
    // }
    n=9;
    A={0,0,0,0,0,0,0,0,1};
    target=1;
    

    Solution ob;
    cout<<ob.findTargetSumWays(A,target);
    return 0;
}