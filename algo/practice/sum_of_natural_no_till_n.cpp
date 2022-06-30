#include <iostream>
using namespace std;
int main(){
    cout<<"enter number till u want sum: ";
    int n;
    cin>>n;
    int sum=0;
    // int i=1;
    // while (i<=n){
    //     sum=sum+i;
    //     i=i+1;
    // }
    for(int i=1;i<=n;i++){
        sum=sum+i;
    }
    cout<<"the sum is : "<<sum;
    return 0;

}