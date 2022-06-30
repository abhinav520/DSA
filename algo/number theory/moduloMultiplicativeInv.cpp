//for what value of x a*x%m=1 i.e. ax==1 (mod 1)
/*
1) Naive Method, O(m) 
2) Extended Euler’s GCD algorithm, O(Log m) [Works when a and m are coprime] 
3) Fermat’s Little theorem, O(Log m) [Works when ‘m’ is prime]
*/
#include <iostream>
using namespace std;
typedef long long ll;
//const int mod=1e9+7;


//naive approach O(m)
int modInverse(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x;
}


//Extended Euclidian Algortithm (gcd(a,m)=1) O(logn)
int gcdExtended(int a, int b, int &x, int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int next=gcdExtended(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return next;
}


//Fermat's The (m is prime) O(log n)
ll power(ll x, ll y,int mod){   //modular exponentiation
	ll res=1;
	while(y){
		if(y%2){  //y is odd 
			res=(x*res)%mod;
		}
		y/=2;
		x=(x*x)%mod;
	}
	return res;
}



int main()
{
    int a=19;
    int m=17;
    int mmi,y;
    gcdExtended(a,m,mmi,y);  //gcdExtended can only be used when both are relative prime gcd(a,m)=1
    cout<<(mmi+m)%m<<endl;      //to handle negative num

    //fermat theorem when m is prime
    cout<<power(a,m-2,m)<<endl;


    //Naive 
    cout<<modInverse(a,m)<<endl;

    return 0;
}