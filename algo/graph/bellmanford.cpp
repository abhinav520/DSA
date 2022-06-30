#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dis(n,INT_MAX);
	    dis[0]=0;
		bool flag;
	    for(int i=0;i<=n;i++){
			flag=false;
	        for(auto x:edges){
	            if(dis[x[0]]!=INT_MAX && dis[x[0]]+x[2]<dis[x[1]]){
	                dis[x[1]]=dis[x[0]]+x[2];
								flag=true;
	            }
	        }
			if(!flag) return 0;
	    }
	    
	    return 1;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}