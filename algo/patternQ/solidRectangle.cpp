#include <iostream>
using namespace std;
int main(){
    int row,column;
    cout<<"enter no of rows: ";
    cin>>row;
    cout<<"enter no of column: ";
    cin>>column;
    for(int i=1;i<=column;i++){
        for(int j=1;j<=row;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}