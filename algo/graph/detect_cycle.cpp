
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool dfs(int s,int parent, vector<int>adj[], int vis[]){
        vis[s]=1;
        for(auto x:adj[s]){
            if(vis[x]==0){ 
                if(dfs(x,s,adj,vis))
                    return true;
            }
            else if(x!=parent) return true;
        }
        return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    bool ans=false;
	    int vis[V];
	    memset(vis,0,sizeof(vis));
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	            ans=dfs(i,-1,adj,vis);
	            if(ans) return true;
	        }
	    }
	    return false;
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
} 