#include<bits/stdc++.h>
using namespace std;


class Solution{
	public:
		long long int countWays(int n, int m)
	{
	    const int k=1e9+7;
	    long long int count[n+1];
	    memset(count,0,sizeof(count));
	    for(int i=1;i<=n;i++){
	        if(i>m){
	            count[i]=(count[i-1]%k+count[i-m]%k)%k;
	        }
	        else if(i<m || i==1){
	            count[i]=1;
	        }
	        else{
	            count[i]=2;
	        }
	    }
	    return count[n];
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.countWays(n, m);
		cout << ans <<"\n";
	}  
	return 0;
}  