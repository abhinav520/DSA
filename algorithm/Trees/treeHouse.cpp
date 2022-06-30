#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n,m;
	cin>>n>>m;
	set<ll> arr;
	//ll arr[n];
	for(int i=0;i<n;i++){
		ll z;
		cin>>z;
		arr.emplace(z);
	}
	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		ll k=(m-(x%m)-2+m)%m;  //diff=2
		auto it=arr.upper_bound(k);
		
		if((*it)>=(k+2)){
			if(it==arr.begin()){
				it=arr.upper_bound(k+m);
			}
			else it--;
		} 
		if(it==arr.end()) it--;
		cout<<((*it)+x)%m<<endl;
		// if((*it)==k+1) {cout<<m-1<<endl;}
		// else{
		// 	while(){
				
		// 	}
		// }
		
		// k=(*it);
		// cout<<((1LL*arr[i])%m+(1LL*x)%m)%m;
	}

	return 0;
}




// #include <bits/stdc++.h>
// using namespace std;

// #define deb(x) 		cout << #x << "=" << x << endl
// #define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
// typedef long long int ll;


// void solve()
// {
//     int n,x;
//     cin>>n>>x;
// }


// int main()
// {
//     int tc=1;
//     cin>>tc;

//     while(tc--){
//         solve();
//     }

//     return 0;
// }