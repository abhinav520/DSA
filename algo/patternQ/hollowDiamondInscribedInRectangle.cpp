#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a length: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i==1){
            for(int j=1;j<=2*n-1;j++){
                cout<<"*";
            }
        }
        else{
            for(int j=1;j<=(n-i+1);j++){
                cout<<"*";
            }
            for(int j=2;j<2*i-1;j++){
                cout<<" ";
            }
            for(int j=1;j<=(n-i+1);j++){
                cout<<"*";
            }
        }
        cout<<endl;
    }

    for(int i=n;i>=1;i--){
        if(i==1){
            for(int j=1;j<=2*n-1;j++){
                cout<<"*";
            }
        }
        else{
            for(int j=1;j<=(n-i+1);j++){
                cout<<"*";
            }
            for(int j=2;j<2*i-1;j++){
                cout<<" ";
            }
            for(int j=1;j<=(n-i+1);j++){
                cout<<"*";
            }
        }
        cout<<endl;
    }
    return 0;
}