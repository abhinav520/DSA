#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter length of pyramid: ";
    cin>>n;
    int i;
    // for(i=1;i<=n;i++){
    //     for(int j=1;j<=(n-i);j++){
    //        cout<<" ";
    //     }
    //     if(i!=1){
    //         cout<<"*";
    //     }
    //     for(int j=2;j<(2*i-1);j++){
    //         cout<<" ";
    //     }
    //     cout<<"*";
    //     cout<<endl;
    // }
    // for(i=n;i>=1;i--){
    //     for(int j=1;j<=(n-i);j++){
    //        cout<<" ";
    //     }
    //     if(i!=1){
    //         cout<<"*";
    //     }
    //     for(int j=2;j<(2*i-1);j++){
    //         cout<<" ";
    //     }
    //     cout<<"*";
    //     cout<<endl;   
    // }
        
    






    for(int i=1;i<=n;i++){
        for(int j=1;j<=(n-i);j++){
            cout<<" ";
        }
        for(int j=1;j<=(2*i-1);j++){
            if(j==1||j==(2*i-1)){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=(n-i);j++){
            cout<<" ";
        }
        for(int j=1;j<=(2*i-1);j++){
            if(j==1||j==(2*i-1)){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}