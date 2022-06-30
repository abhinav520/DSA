/* Given an array of integers of size ‘n’. Our aim is to calculate the maximum sum of ‘k’ consecutive elements in the array. */
#include <iostream>
#include <climits>
using namespace std;
int main()
{
    // int n,k;
    // cin>>n>>k;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    int arr[] = { 1, 4, 2, 10, 2, 3, 20 };
	int k = 4;
	int n = sizeof(arr) / sizeof(arr[0]);

    int currSum=0;
    int maxSum=INT_MIN;
    for(int i=0;i<k;i++){
        currSum+=arr[i];
    }
    for(int i=0;i<(n-k+1);i++){
        currSum= currSum-arr[i]+arr[i+k];
        maxSum=max(currSum,maxSum);
    }
    cout<<maxSum;
    return 0;
}