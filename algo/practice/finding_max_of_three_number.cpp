#include <iostream>
using namespace std;
int main()
{
    int a,b,c;     //declration//
    cout<<"\nEnter first number =";
    cin>>a;
    cout<<"\nEnter second number =";
    cin>>b;
    cout<<"\nEnter third number =";
    cin>>c;
    if(a>b & a>c){
        cout<<"The largest number is "<<a;
        }
    else if(b>a & b>c){
        cout<<"The largest number is "<<b;
        }
    else{
        cout<<"The largest number is "<<c;
        }
    return 0;
}
    