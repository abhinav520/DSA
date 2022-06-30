#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//sqrt(n)
int etf(int n){
    int phi=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            phi*=(i-1);
            phi/=i;
        }    
        while(n%i==0){
            n/=i;
        }
    }
    if(n>1){
        phi*=(n-1);
        phi/=n;
    }
    return phi;
}



int main()
{
    int n;
    cin>>n;
    cout<<etf(n)<<endl;
    return 0;
}