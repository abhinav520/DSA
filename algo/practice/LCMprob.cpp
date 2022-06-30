#include <iostream>
using namespace std;
int gcd(int a, int b){
    if(a==0){                 //Euclidean algo          
        return b;               //gcd(r,0)=r
    }
    return gcd(b,a%b);    //gcd(a,b)=gcd(b,remainder)
}
int lcm(int a, int b)
{
    int Lcm = (a * b) / gcd(a, b);
    return Lcm;
}
int main()
{
    // int tc;
    // cin>>tc;   //testcase
    // int arr[2][tc];
    // for(int i=0;i<tc;i++){
    //     for(int j=0;j<2;j++){
    //         cin>>tc[i][j];
    //     }
    //     cout<<endl;
    // }
    int a, b, l, r;
    cin >> a >> b;
    if (a > b)
    {                   //l is max
        l = a;          //r is min
        r = b;
    }
    else
    {
        l = b;
        r = a;
    }
    int i=0,j=0;
    for(int x=r;x<=l;x++){
        for(int y=r+1;y<=l;y++){
            int Lcm=lcm(x,y);
            if(r<=Lcm && Lcm<=l ){
                i=x;
                j=y;
                break;
            }
            
        }
    }
    if(i==0 && j==0){
        cout<<"-1 -1";
    }
    else{
        cout<<i<<" "<<j;
    }

    return 0;
}