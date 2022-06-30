// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	vector<int> parent,rank;
    void make_set(int v){
        parent[v]=v;
        rank[v]=0;
        //size[v] = 1; when use size
    }
    
    int find_set(int v){ //findParentroot
        if(v==parent[v]) return v;
        return parent[v]=find_set(parent[v]);
    }
    
    void union_sets(int a, int b){
        if(rank[a]<rank[b])
            swap(a,b);
        parent[b]=a;
    
        // size[a] += size[b];   when use size remove next lines
        if(rank[a]==rank[b])    
            rank[a]++;
    }

	int spanningTree(int V,vector<vector<int>> adj[])  //kruskals algorithm
	{
	    set<vector<int>> s;
	    for(int i=0;i<V;i++){
	        for(auto x:adj[i]){
	            vector<int> temp;
	            temp.push_back(x[1]);
	            temp.push_back(min(x[0],i));
	            temp.push_back(max(x[0],i));
	            s.insert(temp);
	            temp.clear();
	        }
	       
	    }
	   // for(auto x:s){
	   //     cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
	   // } 
	    parent.resize(V);
	    rank.resize(V);
	    for(int i=0;i<V;i++){
	        make_set(i);
	    }
	    int cost=0;
	    
        for(auto x:s){
            int a=find_set(x[1]);
            int b=find_set(x[2]);
	        if(a!=b){
	            union_sets(a,b);
	            cost+=x[0];
	        }
	    }
	   // for(auto y:parent){
	   //     cout<<y<<" ";
	   // }
	   // cout<<endl;
	   // for(auto y:rank){
	   //     cout<<y<<" ";
	   // }
	   // cout<<endl;
	    return cost;
	}
    int prims_spanningTree(int V, vector<vector<int>> adj[]) //prims
    {
        bool vis[V]={false};
        int dis[V];
        // memset(dis,INT_MAX,sizeof(dis));
        for(int i=0;i<V;i++) dis[i]=INT_MAX;
        dis[0]=0;
        int parent[V];
        parent[0]=-1;
        set<pair<int,int>> s;
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
                if(!vis[x[0]])
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
        return cost;
    }
};

// { Driver Code Starts.


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

  // } Driver Code Ends