//0-1 knapsack

#include <bits/stdc++.h>
using namespace std;
const int N=100,M=1000;
//below is the recursive approach
int knapsack(int val[], int wt[], int n, int W)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n - 1] > W)
    {
        return knapsack(val, wt, n-1, W);
    }
    return max(val[n - 1] + knapsack(val, wt, n-1, W - wt[n - 1]), knapsack(val, wt, n-1, W));
}

//lets do memoization as some recursive function are repeating
int arr[N][M];     //this array has to made based on the constraint
int MemoizeKnapsack(int val[], int wt[],int n, int w){
    if(n==0|| w==0){
        return 0;
    }
    if(arr[n][w]!=-1){
        return arr[n][w];
    }
    else{
        if(wt[n-1]>w){
            return arr[n][w]=MemoizeKnapsack(val,wt,n-1,w);
        }
        else{
            return arr[n][w]=max(val[n-1]+MemoizeKnapsack(val,wt,n-1,w-wt[n-1]),MemoizeKnapsack(val,wt,n-1,w));
        }
    }
}

//Lets do Dynammic Prograaming, ie iterative sol, no recursion
int Knapsack(int val[],int wt[],int n,int w){
    int dp[n+1][w+1];
    //initialization of dp
    for(int l=0;l<(w+1);l++){
        dp[0][l]=0;
    }
    for(int k=0;k<n+1;k++){
        dp[k][0]=0;
    }
    for(int i=1;i<n+1;i++){            //i->number of elemets & j->weight
        for(int j=1;j<w+1;j++){
            if(wt[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
        }
    }
    return dp[n][w];
}


int main()
{
    memset(arr, -1, sizeof(arr));
    int val[] = {60, 100, 120};
    int wt[] = {1, 2, 3};
    int W = 7;
    int n = sizeof(val) / sizeof(val[0]);
    cout << Knapsack(val, wt, n, W)<<endl;
    cout << MemoizeKnapsack(val, wt, n, W)<<endl;
    return 0;
}