#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        bool vis[V]={false};
        int dis[V];
        // memset(dis,INT_MAX,sizeof(dis));
        for(int i=0;i<V;i++) dis[i]=INT_MAX;
        dis[0]=0;
        int parent[V];
        parent[0]=-1;
        set<pair<int,int>> s;  //dis,node (dis is used just for sorting)
        // s.insert(dis[0],0);
        for(int i=0;i<V;i++){
            s.insert({dis[i],i}); 
        }
        int u;
        while(!s.empty()){
            auto it=s.begin();
            u=it->second;
            vis[u]=true;
            s.erase(it);
            for(auto x:adj[u]){
                if(!vis[x[0]])  //if not visited
                if(dis[x[0]]>x[1]){
                    auto itr=s.find({dis[x[0]],x[0]});
                    if(itr!=s.end())
                        s.erase(itr);
                    dis[x[0]]=x[1];
                    parent[x[0]]=u;
                    s.insert({dis[x[0]],x[0]});
                }
            }
        }
        int cost=0;
        for(int i=0;i<V;i++){
            cost+=dis[i];
        }
        //path to get mst
        // vector<pair<int,int>> path;
        // for(int i=0;i<V;i++){
        //     path.push_back({i,parent[i]});
        // }
        return cost;
    }
};



int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
