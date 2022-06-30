#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	vector<vector<int>> scc;
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    void dfs(int u, int &t,int disc[], int low[], stack<int> &stk,bool instk[], int V, vector<int> adj[]){
        // vis[u]=true;
        disc[u]=t;
        low[u]=t;
        t++;
        stk.push(u);
        instk[u]=true;
        for(auto v:adj[u]){
            if(disc[v]==-1){
                dfs(v,t,disc,low,stk,instk,V,adj);
                low[u]=min(low[u],low[v]);
            }
            else if(instk[v]){  //if there is a back edge
                low[u]=min(low[u],low[v]);
            }
        }
        if(low[u]==disc[u]){
            vector<int> temp;
            int val;
            do{
                val=stk.top();
                temp.push_back(val);
                instk[val]=false;
                stk.pop();
            }while(disc[val]!=low[val]);
            sort(temp.begin(),temp.end());
            scc.push_back(temp);
        }
    }
    
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        stack<int> stk;
        bool instk[V]={false};
        // bool vis[V]={false};
        static int t=0; //discovery time
        int disc[V];  
        int low[V];
        memset(disc,-1,sizeof(disc));
        for(int i=0;i<V;i++){
            if(disc[i]==-1){
                dfs(i,t,disc,low,stk,instk,V,adj);
            }
        }
        
        // stable_sort(scc.begin(),scc.end());
        sort(scc.begin(),scc.end());
        return scc;
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
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

/*
1
5 5
1 0
0 2
2 1
0 3
3 4
output:0 1 2,3,4,
*/

/*
1
9 4
2 8
8 0
7 5
5 5
*/
// output
// 0,1,2,3,4,5,6,7,8,