//Quest-->  https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/ispalin/

//brute force

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
// 	int t;
// 	cin>>t;
// 	while(t--){
// 		int n,q;
// 		cin>>n>>q;
// 		string s;
// 		cin>>s;
// 		for(int i=0;i<q;i++){
// 			int l,r;
// 			cin>>l>>r;
// 			int arr[26]={0};    //0 based indexing
// 			l--;r--;
// 			for(int j=l;j<=r;j++){
// 				arr[s[j]-'a']+=1;
// 			}
// 			int oddCt=0;
// 			for(int j=0;j<26;j++){
// 				if(arr[j]%2!=0){
// 					oddCt++;
// 				}
// 			}
// 			if(oddCt==0 || oddCt==1){
// 				cout<<"YES"<<endl;
// 			}
// 			else{
// 				cout<<"NO"<<endl;
// 			}
// 		}
// 	}
// 	return 0;
// }


//effeicient algo
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int hsh[26][N];            //global var are always initialised with 0
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		string s;
		cin>>s;

		for(int i=0;i<26;i++){
			for(int j=0;j<=n;j++){
				hsh[i][j]=0;
			}
		}

//count array
		// for(int i=0;i<26;i++){    //---->bad coder coding O(n*26)
		// 	for(int j=0;j<n;j++){
		// 		if(s[j]-'a'==i) {hsh[i][j]+=1;}
		// 	}
		// }
		for(int i=0;i<n;i++){        //-->good coder coding O(n)
			hsh[s[i]-'a'][i+1]+=1;
		}
//prefix sum array
		for(int i=0;i<26;i++){
			for(int j=1;j<=n;j++){
				hsh[i][j]+=hsh[i][j-1];
			}
		}


		for(int i=0;i<q;i++){
			int l,r;
			cin>>l>>r;
			int oddCt=0;
			for(int j=0;j<26;j++){
				if((hsh[s[j]-'a'][r]-hsh[s[j]-'a'][l-1])%2!=0){
					oddCt++;
				}
			}
			if(oddCt==0 || oddCt==1){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}

