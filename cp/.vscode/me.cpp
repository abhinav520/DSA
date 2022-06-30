#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    int ans=n-1;
	    int k,d;
	    for(int i=3;i<=n;i++){
	        k=m-m%i;
	        for(int j=2; j<i && j*j<=k; j++){
	            if(k%j==0){
	                if((k/j)!=j && (k/j)<i)
	                ans+=2;
	                else ans+=1;
	            }
	        }
	    }    
	    cout<<ans<<endl;
	}
	return 0;
}