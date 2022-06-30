// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// int gcd(int a,int b){
//     if(b==0) return a;
//     return gcd(b,a%b);
// }
// int main()
// {
//     // int t;
//     // cin>>t;
//     // while(t--){
//     //     int n;
//     //     cin>>n;
//     //     vector<int> vec(n);
//     //     for(int i=0;i<n;i++){
//     //         cin>>vec[i];
//     //     }
//     //     for 
//     // }
//     cout<<gcd(24,36)<<endl;
//     cout<<0%10;
//     return 0;
// }


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
	    int a,b;
	    for(int i=2;i<n;i++){
	        for(int j=i+1;j<=n;j++){
	            if((m%i)%j==(m%j)%i){
	                ans++;
	            }
	        }
	    }
	    cout<<ans<<endl;
	}
	
	return 0;
}


