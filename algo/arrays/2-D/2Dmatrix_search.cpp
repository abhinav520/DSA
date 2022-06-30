#include <iostream>
using namespace std;
int main()
{
    int r,c;
    cin>>r>>c;
    int arr[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }
    int target;
    cout<<"Enter the value to be searched: ";
    cin>>target;
    int n=0, m=c-1;
    bool flag= false;
    //starting iteration from right upper matrix
    while(n<r && m>=0){
        if(arr[n][m]==target){
            cout<<"The "<<target<<" found at index : "<<n<<", "<<m;
            flag=true;
        }
        arr[n][m]>target ? m-- : n++ ;
    }
    if(flag==false){
        cout<<"The "<<target<<" is not present in matrix.";
    }

    return 0;
}