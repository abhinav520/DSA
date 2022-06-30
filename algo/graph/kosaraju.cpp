#include<bits/stdc++.h>
using namespace std;



class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void finish_time_stack(int start,int vis[],stack<int> &stk, int V, vector<int> adj[]){
	    //just simple dfs
	    vis[start]=1;
	    for(auto x:adj[start]){
	        if(vis[x]==0){
	            finish_time_stack(x,vis,stk,V,adj);
	        }
	    }
	    stk.push(start);
	}
	
	void transpose_graph(int V,vector<int> adj[],vector<int> tgra[]){
	    for(int i=0;i<V;i++){
	        for(int y:adj[i]){
	            tgra[y].push_back(i);
	        }
	    }
	}
    
	void dfs(int start,int vis[],int V,vector<int> tgra[]){
        vis[start]=1;
        for(auto x:tgra[start]){
            if(vis[x]==0){
                dfs(x,vis,V,tgra);
            }
        }
    }
    
    // above are utility function
    
    int kosaraju(int V, vector<int> adj[])
    {
        int vis[V];
        memset(vis,0,sizeof(vis));
        // step1
        stack<int> stk;
        for(int i=0;i<V;i++){
            if(vis[i]==0)
                finish_time_stack(i,vis,stk,V,adj); //dfs
        }
        // step2
        vector<int> tgra[V];
        transpose_graph(V,adj,tgra);
        // step3
        int count=0;
        memset(vis,0,sizeof(vis));
        int u;
        while(!stk.empty()){
            u=stk.top();
            stk.pop();
            if(vis[u]==0){
                dfs(u,vis,V,tgra);
                count++;
            }
        }
        return count;
    }
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

/*
5 5
1 0
0 2
2 1
0 3
3 4
*/
//output
// 3


