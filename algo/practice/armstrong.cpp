#include <iostream>
using namespace std;
int main(){
    int m;
    cout<<"Enter a number: ";
    cin>>m;
    int sum=0;
    int orgNum=m;    
    while(m>0){
        int rem=m%10;
        sum=sum + (rem*rem*rem);
        m=m/10;
    }
    if(sum==orgNum){
        cout<<"the number is an armstrong";
    }
    else{
        cout<<"the number is not an armstrong";
    }
    return 0;
}