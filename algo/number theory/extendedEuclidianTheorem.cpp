#include <bits/stdc++.h>
using namespace std;
struct Triplet{
    int gcd;
    int x;
    int y;
}ans;

Triplet ExtendedEuclidean(int a, int b){
    if(b==0){
        ans.x=1;
        ans.y=0;
        ans.gcd=1;
        return ans;
    }
    Triplet next=ExtendedEuclidean(b,a%b);
    ans.gcd=next.gcd;
    ans.x=next.y;
    ans.y=next.x-(a/b)*next.y;
    return ans;
}

int gcd(int a, int b, int &x, int &y){
    if(b==0){
        x=1;
        y=0;   //alpha- any value
        return a;
    }
    int x1,y1;
    int next=gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return next;
}
//solution of ax+by=gcd(a,b)
void extendgcd(int a, int b, int *v)
{
    if (b == 0)
    {
        v[0] = 1;  //x
        v[1] = 0;  //y
        v[2] = a;  //gcd
        return;
    }
    extendgcd(b, a % b, v);
    int x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;
} // pass an arry of size 3
int main()
{
    // cout<<ExtendedEuclidean(57,81).x<<" "<<ExtendedEuclidean(57,81).y<<endl;
    // int x,y;

    // //---------------------------------------
    // cout<<gcd(930,2430,x,y)<<"\n";
    // cout<<x<<" "<<y;
    //---------------------------------------
    int arr[3];
    extendgcd(2430,930,arr);
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<"\n";
    //---------------------------------------
    return 0;
}