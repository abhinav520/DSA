#include <iostream>
using namespace std;
int countPathMaze(int n,int m, int i=1, int j=1){
    if(i==n && j==m){
        return 1;
    }
    if(i>n||j>m){
        return 0;
    }
    return countPathMaze(n,m,i+1,j)+countPathMaze(n,m,i,j+1);;
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<countPathMaze(n,m);
    return 0;
}