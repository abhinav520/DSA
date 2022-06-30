/*
Transpose of a square matrix
time complexcity=O(n^2)
space complexcity=O(1) only in case of square matrix as no extra space for new matrix is used.
in m*n matrix we have to create new space in order to store n*m ie its transpose.
*/
#include <iostream>
using namespace std;
int main()
{
    int n;  
    cin>>n;
    int matrix[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(i==j){
                ;
            }
            //swap
            int temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }
    //print transpose
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}