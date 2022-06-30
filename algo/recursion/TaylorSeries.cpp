// ex = 1+ x + (x^2/2!) + (x^3/3!)+...
#include <iostream>
using namespace std;
//Taylor series using static function
double e(int x,int n){          //--->This func do n*(n+1) multiplication
    static double f=1,p=1;      //    T.C of multiplication=O(n^2) 
    double result=0;h
    if(n==0){
        return 1;
    } 
    result+=e(x,n-1);
    f=f*n;
    p=p*x;
    return result+p/f;
}

//reducing quadratic time to linear time
// Taylors series using Horner's rule--taking commons[1+1/x[1+x/2]
double e(double x,int n){     //--->This func do n multiplication
    static double result=1;          //    T.C of multiplication=O(n)
    if (n==0){
        return result;
    }
    result=result*(x/n)+1;
    return e(x,n-1);

} 
int main()
{
    cout<<e(2.0,4);
    return 0;
}