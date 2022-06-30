#include <iostream>
using namespace std;

void inc(int *p){
    *p=*p+1;
}

int main()
{
    int a=10;
    inc(&a);
    cout<<a;

    return 0;
}