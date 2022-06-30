#include <iostream>
using namespace std;
int main(){
    int n;  //n is in decimal
    cin>>n;
    //__builtin_Function
    // cout<<"Num of leading 0s: "<<__builtin_clz(n);    //here n is in decimal
    // cout<<"\nNum of trailing 0s: "<<__builtin_ctz(n);
    // cout<<"\nNum of 1 bits: "<<__builtin_popcount(n);
    // cout<<"\nParity of num: "<<__builtin_parity(n);    

    //Parity Check (Time Complexity=logx x=no of bits)
    int N=n;
    bool parity=0;
    while(N){
       //unset 1 bit in every iteration and inverse the parity
        N= N & (N-1);
        parity=!parity;
    }

    // Trailing 0s
    int trail0=0, num1=0;
    while(n){
        if((n&1)==0){
            trail0++;
            n=n>>1;
        }
        else
            break;
    }

    //Num of 1 bits
    while(n){
        if((n&1)==1){
            num1++;
            n=n>>1;
        }
        else{
            n=n>>1;
        }
    }
    cout<<"Num of leading 0s: "<<(32-num1-trail0)<<endl;
    cout<<"Num of trailing 0s: "<<(trail0)<<endl;
    cout<<"Num of 1 bits: "<<num1<<endl;
    cout<<"Parity of num (0-even parity; 1-odd parity): "<<parity;
}