#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;



bool isPrime(ll n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int main(){
    cout<<"enter a number:";
    int number;
    cin>>number;

    int flag=0;
    for(int i=2;i*i<=number;i++){
        if (number%i==0){
            flag=1;
            break;
        }
    }
    if(number==1){
        cout<<"Neither Prime nor Composite";
    }
    else if(flag==0){
        cout<<"Prime";
    }
    else{
        cout<<"Non prime";
    }
    
    return 0;
}