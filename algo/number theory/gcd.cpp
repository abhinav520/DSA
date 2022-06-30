#include <iostream>
using namespace std;
int gcd(int a, int b){
    if(b==0){                 //Euclidean algo          
        return a;               //gcd(r,0)=r
    }
    return gcd(b,a%b);    //gcd(a,b)=gcd(b,remainder)
}


int main()
{
    int a,b,hcf;
    cin>>a>>b;
    // for(int i=1;i<=a && i<=b;++i){   //gcd is the highest number that divides both a and b.
    //     if(a%i==0 && b%i==0){        //lcm is the lowest number which is divisible by both a and b.   
    //         hcf=i;
    //     }
    // }
    // cout<<hcf<<endl;
    hcf=gcd(a,b);
    cout<<hcf<<endl;
    int lcm=(a*b)/hcf;   //lcm*gcd=a*b <-- imp relation
    cout<<lcm;
    return 0;
}
