// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
    //Function to find the number of islands.

    //2222222222222(2d)ddddddddddddd graph dfs

    bool isSafe(int i,int j,int n,int m){
        if(i>=0 && j>=0 && i<n && j<m){
            return true;
        }
        return false;
    }
    
    void dfs(int i,int j,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
		grid[i][j]='0';
		// cout<<n<<" "<<m<<"\n";
        if(i-1>=0 && grid[i-1][j]!='0'){
            dfs(i-1,j,grid);
            // grid[i-1][j]='0';
        }
        if(i-1>=0 && j-1>=0 && grid[i-1][j-1]!='0'){
            dfs(i-1,j-1,grid);
            // grid[i-1][j-1]='0';
        }
        if(i-1>=0 &&  j+1<m &&  grid[i-1][j+1]!='0'){
            dfs(i-1,j+1,grid);
            // grid[i-1][j+1]='0';
        }
        if(j-1>=0 && grid[i][j-1]!='0'){
            dfs(i,j-1,grid);
            // grid[i][j-1]='0';
        }
        if(j+1<m && grid[i][j+1]!='0'){
            dfs(i,j+1,grid);
            // grid[i][j+1]='0';
        }
        if(i+1<n && grid[i+1][j]!='0'){
            dfs(i+1,j,grid);
            // grid[i+1][j]='0';
        }
        if(j-1>=0 && i+1<n && grid[i+1][j-1]!='0'){
            dfs(i+1,j-1,grid);
            // grid[i+1][j-1]='0';
        }
        if(j+1<m && i+1<n && grid[i+1][j+1]!='0'){
            dfs(i+1,j+1,grid);
            // grid[i+1][j+1]='0';
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!='0'){
                    cnt++;
                    dfs(i,j,grid);
                    
                }
            }
        }
        return cnt;
    }
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends