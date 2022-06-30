#include <iostream>
using namespace std;
int octToDeci(int oct){
    int num=0;
    int multiplier=1;
    while(oct>0){
        num+=multiplier*(oct%10);
        multiplier*=8;
        oct=oct/10;
    }
    return num;
}

int main(){
    int n;
    cout<<"enter number in octal: ";
    cin>>n;
    cout<<"The octal in decimal: "<<octToDeci(n)<<endl;
    return 0;
}