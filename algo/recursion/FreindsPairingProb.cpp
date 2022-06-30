//https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1#
// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        const int m=1e6;
        static int arr[m];
        if(arr[m]!=0){
            return arr[n];
        }
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        return arr[n]=countFriendsPairings(n-1)+countFriendsPairings(n-2);
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends