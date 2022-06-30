//Using Fermets little theorem
/*a^(p-1) ≡ 1 (mod p)   or a^(p-2) ≡ a^(-1) (mod p) 
OR 
a^(p-1) % p = 1 
Here a is not divisible by p. */
#include <iostream>
using namespace std;
typedef long long ll;
const int m=1e9+7;

int gcd(int a, int b){
    if(a==0){
        return b;
    }
    else if(b==0){
        return a;
    }
    else if(a==b){
        return a;
    }
    else if(a>b){
        return gcd(b,a%b);
    }
    else{
        return gcd(b%a,a);
    }
}

ll power(ll a, int p, int m){
    ll res=1;
    while(p){
        if(p%2){
            res=((res%m)*(a%m))%m;
        }
        p/=2;
        a=((a%m)*(a%m))%m;
    }
    return res;
}

int main()
{
    cout<<gcd(12,6)<<endl;
    //cout<<power(804289384,m-2,m);
    return 0;
}
