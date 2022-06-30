#include <iostream>
using namespace std;
int main(){
    cout<<"enter number : ";
    int number;
    cin>>number;
    for(int i=1;i<=number;i++){
        for(int j=1;j<=10;j++){
            cout<<i<<"*"<<j<<"="<<i*j<<endl;
        }

    }
    return 0;
}