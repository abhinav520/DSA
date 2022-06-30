#include <bits/stdc++.h>
using namespace std;
double eps=1e-6;  //will give precision upto 5 decimall places

double nTimesMultiply(double mid,int n){
    double product=1;
    for(int i=1;i<=n;i++){
        product*=mid;
    }
    return product;
}
double nthroot(int n, double x){
    double lo = 1, hi = x, mid;
    while (hi - lo > eps)
    {
        mid = (hi + lo) / 2;
        if (nTimesMultiply(mid, n) < x)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    return (lo+hi)/2;
}
int main()
{
    double x;
    int n;
    cin>>x>>n;
    double lo=1,hi=x,mid;
    while(hi-lo > eps){
        mid=(hi+lo)/2;
        if(nTimesMultiply(mid,n)<x){
            lo=mid;
        }
        else{
            hi=mid;
        }
    }
    cout<<nthroot(n,x)<<endl;
    // tc=O(p*log(n*(10^d)))  p:pth root of number n with d:decimal_places accuracy
    cout<<"By binary search: "<<setprecision(10)<<lo<<" "<<hi<<endl;
    cout<<"By builtin pow function: "<<setprecision(5)<<pow(x,1.0/n)<<endl;
    return 0;
}