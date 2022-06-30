// A C++ program to demonstrate working of Chinise remainder
// Theorem
#include<bits/stdc++.h>
using namespace std;
 
// k is size of num[] and rem[].  Returns the smallest
// number x such that:
//  x % num[0] = rem[0],
//  x % num[1] = rem[1],
//  ..................
//  x % num[k-1] = rem[k-1]
// Assumption: Numbers in num[] are pairwise coprime
// (gcd for every pair is 1)


int gcdExtended(int a, int b, int &x, int &y);

int inv(int a, int m){
    if(m==1) return 0;
    int x, y;
    gcdExtended(a,m,x,y);
    if(x<0) x+=m;
    return x;
}
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

int crt(vector<pair<int,int>> v){    //v[{num,rem}]
    int n=v.size();
    int ans=0;

    int m=1; //m=p1*p2*p3*.....pn
    for(int i=0;i<n;i++){
        m *= v[i].first;
    }

    for(int i=0;i<n;i++){
        int t=1;
        for(int j=0;j<i;j++){
            t *= v[j].first;
            t *= inv(v[j].first,v[i].first);
            t%=m;
        }

        //x%pi=ki
        //(x1 +x2p1 + x3p1p2 + ....+ xip1p2p3..p(i-1) +0+0+0....+0 = ki)%pi
        //(ki = ans + xip1p2p3...p(i-1)) (under mod pi)
        //xi = (ki-ans)*inv(p1)*inv(p2)*....inv(p(i-1)) (under mod pi)

        ans+=(t*(v[i].second-ans+m)%m);
        ans%= m;
    }

    return ans;
    
} 

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    cout<<crt(v);
    return 0;
}