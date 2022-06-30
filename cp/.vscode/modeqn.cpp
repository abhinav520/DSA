#include <iostream>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(z,x, y) cout  << #z << "=" << z << "," << #x << "=" << x << "," << #y << "=" << y << endl
typedef long long ll;

int main() {
	int t;
	cin>>t;
	while(t--){
        // int** f=new int*[500001];
        // for(int i=2;i<=500000;i++){
        //     f[i]=new int[]
        // }
        int m=2;
        while(m<=500000){
            for(int i=2;i*i<=m;i++){
                
            }
        }
        
	    int n,m;
	    cin>>n;
	    int ans=n-1;
	    int a,b;
        m=100;
        while(m--)
	    for(int i=2;i<n;i++){
	        for(int j=i+1;j<=n;j++){
	            if((m%i)%j==(m%j)%i){
                    deb3(m,i,j);
	                ans++;
	            }
	        }
	    }
        deb2(n,m);
	    cout<<ans<<endl;
	}
	return 0;
}