#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dis(V);
        for(int i=0;i<V;i++){
            dis[i]=INT_MAX;
        }
        dis[S]=0;
        set<pair<int,int>> s;  //(dis,node)
        s.insert({dis[S],S});
        while(!s.empty()){
            auto it=*(s.begin());
            int u=it.second;
            s.erase(it);
            for(auto x:adj[u]){
                //Relaxation
                if(dis[u]+x[1]<dis[x[0]]){
                    auto itr=s.find((make_pair(dis[x[0]],x[1])));
                    if(itr!=s.end())
                        s.erase(itr);
                    dis[x[0]]=dis[u]+x[1];
                    s.insert({dis[x[0]],x[0]});
                }
            }
        }
        return dis;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
