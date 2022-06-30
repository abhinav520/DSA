#include <iostream>
using namespace std;
int main(){
    float a,b;
    cout<<"Enter two number: ";
    cin>>a>>b;
    char op;
    cout<<"Enter operator: ";
    cin>>op;
    switch(op)
    {
    case('+'):
        cout<<a<<"+"<<b<<"="<<a+b;
        break;
    case('-'):
        cout<<a<<"-"<<b<<"="<<a-b;
        break;
    case('*'):
        cout<<a<<"*"<<b<<"="<<a*b;
        break;
    case('/'):
        cout<<a<<"/"<<b<<"="<<a/b;
        break;
    default:
        cout<<"invalid operator!";
    }
    return 0;
}