#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<int> adj[],int u,int d, int &path,bool vis[]){
        if(u==d){
            path++;
            return;
        }
        vis[u]=true;
        for(auto x:adj[u]){
            if(!vis[x])
                dfs(adj,x,d,path,vis);
        }
        vis[u]=false;
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){

	    vector<int> adj[n];
	    for(auto x:edges){
	        adj[x[0]].push_back(x[1]);
	    }
	    bool vis[n]={false};
	    int path=0;
	    dfs(adj,s,d,path,vis);
	    return path;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
} 