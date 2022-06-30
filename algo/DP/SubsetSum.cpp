#include <iostream>
using namespace std;

//Memoization
int isSubsetSum(int set[],int n, int sum){
    static int arr[100][1000];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            arr[i][j]=-1;
        }
    }
    if(n==0 && sum!=0){
        return 0;
    }
    if(sum==0){
        return 1; 
    }
    if(arr[n][sum]!=-1){
        return arr[n][sum];
    }
    if(set[n-1]>sum){
        return arr[n][sum]=isSubsetSum(set,n-1,sum);
    }
    else{
        return arr[n][sum]=(isSubsetSum(set,n-1,sum-set[n-1]) || isSubsetSum(set,n-1,sum))?1:0;
    }
}

//TopDown
int isSubsetSumDP(int set[],int n, int sum){
    int arr[n+1][sum];
    //initialization
    for(int l=0;l<n+1;l++){
        arr[l][0]=1;
    }
    for(int k=1;k<sum+1;k++){
        arr[0][k]=0;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(set[i-1]>j){
                arr[i][j]=arr[i-1][j];
            }
            else{
                arr[i][j]=(arr[i-1][j-set[i-1]] || arr[i-1][j])/*?1:0*/;
            }
        }
    }
    return arr[n][sum];
}


int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum =12;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSumDP(set, n, sum) !=0)
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");
    return 0;
}