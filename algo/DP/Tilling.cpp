//It is similar to nth fibbonaci num
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    long long numberOfWays(long long N) {
        const int m=1e5+2;
        static long long int arr[m]={0};
        const int M=1e9+7;
        if(arr[N]!=0){
            return arr[N];
        }
        if(N==1){
            return 1; 
        }
        if(N==2){
            return 2;
        }
        else{
            return arr[N]=(numberOfWays(N-1)%M + numberOfWays(N-2)%M)%M;
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}  // } Driver Code Ends