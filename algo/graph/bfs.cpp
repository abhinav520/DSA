#include <iostream>
#include <list>
#include <queue>
#include <stack>

using namespace std;

void BFS(int u, int A[][8], int n){  //using queue

    int visited[8]={0};
    queue<int> q;
    cout<<u<<" ";
    visited[u]=1;
    q.push(u);
    while(!q.empty()){
        u=q.front(); 
        q.pop();
        for(int i=1;i<n;i++){
            if(A[u][i]==1 && visited[i]!=1){
                cout<<i<<" ";
                visited[i]=1;
                q.push(i);
            }
        }
    }
    cout<<endl;
}

// Simpler and adds elements to stack from end
void DFS(int u, int A[][8],int n){   //using own stack
    int visited[8]={0};
    stack<int> stk;
    stk.push(u);
    while (!stk.empty()){
        u = stk.top();
        stk.pop();
 
        if (visited[u] != 1){
            cout << u << ", " << flush;
            visited[u] = 1;
 
            for (int v=n-1; v>=0; v--){
                if (A[u][v] == 1 && visited[v] == 0){
                    stk.emplace(v);
                }
            }
        }
    }
    cout<<endl;
}
void dfsRec(int u, int A[][8], int n){  //recursion(using stack of program)
    static int visited[8]={0};
    cout<<u<<" ";
    visited[u]=1;
    for(int i=1;i<n;i++){
        if(A[u][i]==1 && visited[i]!=1){
            dfsRec(i,A,n);
        }
    }

}
void dfs(int u, int A[][8], int n){  //recursion(using stack of ds)
    int visited[8]={0};
    cout<<u<<" ";
    visited[u]=1;
    stack<int> stk;
    stk.push(u);
    
    while(!stk.empty()){
        u=stk.top();
        bool flag=false;
        for(int i=1;i<n;i++){
            if(A[u][i]==1 && visited[i]!=1){
                visited[i]=1;
                cout<<i<<" ";
                stk.push(i);
                flag=true;
                break;
            }
        }
        if(!flag) stk.pop();
    }

}

int main()
{
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    int u = 5;  //starting node
    cout << "BFS Vertex: " << u << " -> " << flush;
    BFS(u, A, 8);
    cout << endl;

    cout << "DFS Vertex: " << u << " -> " << flush;
    DFS(u, A, 8);
    cout << endl;
 
    cout << "dfsRec Vertex: " << u << " -> " << flush;
    dfsRec(u, A, 8);
    cout << endl;
    cout << "dfs Vertex: " << u << " -> " << flush;
    dfs(u, A, 8);
    cout << endl;
    return 0;

}
