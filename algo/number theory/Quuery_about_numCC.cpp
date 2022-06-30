// //https://www.codechef.com/problems/QNUMBER

// #include <bits/stdc++.h>
// using namespace std;

// #define deb(x) 		cout << #x << "=" << x << endl
// #define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
// typedef long long int ll;

// int main()
// {
//     ll n;
//     cin>>n;
//     int q=1;
//     cin>>q;
//     vector<ll> v;
//     for(ll i=1;i*i<=n;i++){
//         if(n%i==0){
//             v.push_back(i);
//             if(n/i!=i){
//                 v.push_back(n/i);
//             }
//         }
//     }

//     while(q--){
//         int t,k;
//         cin>>t>>k;
//         int flag=0;
//         if(t==1){
//             ll ct=0;
//             for(ll x:v){
//                 if(k%x==0){
//                     ct++;
//                 }
//             }
//             cout<<ct<<endl;
//         }
//         else if(t==2){
//             ll ct=0;
//             for(ll x:v){
//                 if(x%k==0){
//                     ct++;
//                 }
//             }
//             cout<<ct<<endl;
//         }
//         else{
//             ll ct=0;
//             for(ll x:v){
//                 if(x%k!=0){
//                     ct++;
//                 }
//             }
//             cout<<ct<<endl;
//         }
        
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

#define deb(x) 		cout << #x << "=" << x << endl
#define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef long long int ll;

int main()
{
	int tc=1;
	cin>>tc;

	while(tc--){
		int n,x,y;
		cin>>n;
		set<pair<int,int>> s;
		set<int> ans;
		for(int i=0;i<n;i++){
			cin>>x>>y;
			s.insert({x,y});
		}
		for(auto i:s){
			for(auto j:s){
				if(i.first==j.first || i.second==j.second) continue;
				if(s.find({i.first,j.second})==s.end() || s.find({j.first,i.second})==s.end()) continue;
				// pair<int,int> p1,p2;
				// p1=make_pair(i.first,j.second);
				// p2=make_pair(j.first,i.second);
				// if(s.find(p1)==s.end() || s.find(p2)==s.end()) continue;
				ans.insert((j.second-j.first)*(i.second-i.first));
			}
		}
		cout<<(*ans.rbegin())-(*ans.begin())<<endl;
	}


	// 	int flag=0;
	// 	int flg2=0 ,flg1=0;
	// 	int u=0;
	// 	int a,b,c,d;
	// 	while(flag==0 || flg2==0 || flg1==0)
	// 	{	
	// 		u++;
	// 		static auto it1=s.begin();
	// 		static auto it2=s.rbegin();
	// 		flag=1;
	// 		if(it1->first==it2->first || it1->second==it2->second){
	// 			flag=0;
	// 		}
	// 		a=it1->first;
	// 		b=it2->second;
	// 		c=it1->second;
	// 		d=it2->first;
	// 		pair<int,int> p1(a,b),p2(c,d);
	// 		// p1=make_pair(a,b);
	// 		// p2=make_pair(c,d);
	// 		flg2=0,flg1=0;
	// 		for(auto r:s){
	// 			if(r==p1){
	// 				flg1=1;
	// 			}
	// 			if(r==p2){
	// 				flg2=1;
	// 			}
	// 			if(flg1==1 && flg2==1) break;
	// 		}
			
	// 		if(u%2) it2--;
	// 		else it1++;
	// 	}
	// 		cout<<(1LL*(b-d)*(c-a))<<endl;		
	// }

	return 0;
}
