#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int z=1e9+7;
ll power(int m){
    if(m==0){
        return 1;
    }
    ll k=power(m/2);
    if(m%2==0){
        return k*k;
    }
    else{
        return 2*k*k;
    }
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    cout<<power(n-1)<<endl;
	}
	return 0;
}
