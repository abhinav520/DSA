#include <iostream>
using namespace std;
int fibonacci(int num){
    if(num==1){
        return 0;
    }
    else if(num==2){
        return 1;
    }
    else{
        return (fibonacci(num-1) + fibonacci(num-2));
    }
}
int main()
{
    int n;
    cout<<"enter length of a fibonacci: ";
    cin>>n;
    for(int i=1;i<=n;i++){
            cout<<fibonacci(i)<<"  ";
    }

    return 0;
}
