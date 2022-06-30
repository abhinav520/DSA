#include <iostream>
using namespace std;
int binToDeci(int bin){
    int num=0;
    int multiplier=1;
    while(bin>0){
        num+=multiplier*(bin%10);
        multiplier*=2;
        bin=bin/10;
    }
    return num;
}


int main(){
    int n;
    cout<<"enter number in binary: ";
    cin>>n;
    cout<<"The binary in decimal: "<<binToDeci(n)<<endl;
    return 0;
}