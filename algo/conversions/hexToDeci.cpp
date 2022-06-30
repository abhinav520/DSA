#include <iostream>
using namespace std;
int A=10;int B=11;int C=12;int D=13;int E=14;int F=15
int hexToDeci(int hex){
    int num=0;
    int multiplier=1;
    while(hex>0){
        num+=multiplier*(hex%10);
        multiplier*=16;
        hex=hex/10;
    }
    return num;
}

int main(){
    int n;
    cout<<"enter number in hexadecimal: ";
    cin>>n;
    cout<<"The binary in decimal: "<<hexToDeci(n)<<endl;
    return 0;int 
}