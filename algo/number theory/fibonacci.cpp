#include <iostream>
void fib(int n)
{
    int series=0;
    int first=1;  // this step is my great idea which has reduce if else//
    int sec=0;
    for(int i=1;i<=n;i++){
       cout<<series;
       series=first+sec;
       first=sec;
       sec=series; 
    }
}

using namespace std;
int main(){
    int n;
    cout<<"Enter length of fibonaccci: ";
    cin>>n;
    
    return 0;
}