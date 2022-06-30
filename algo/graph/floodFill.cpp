// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isSafe(int i,int j,int n,int m){
        if(i>=0 && j>=0 && i<n && j<m){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<int>> &img,int i,int j,int color){
        int n=img.size();
        int m=img[0].size();
        int k=img[i][j];
        img[i][j]=color;
        if(isSafe(i-1,j,n,m) && img[i-1][j]==k) dfs(img,i-1,j,color);
        if(isSafe(i+1,j,n,m) && img[i+1][j]==k) dfs(img,i+1,j,color);
        if(isSafe(i,j-1,n,m) && img[i][j-1]==k) dfs(img,i,j-1,color);
        if(isSafe(i,j+1,n,m) && img[i][j+1]==k) dfs(img,i,j+1,color);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]!=newColor)
            dfs(image,sr,sc,newColor);
		return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends