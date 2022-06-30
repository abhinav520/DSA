#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll m=n;
        int count=0;
        while(m>0){
            m/=10;
            count++;
        }
        int ans=0;
        ans=(count-1)*9;
        string s="";
        while(count--){
            s +="1";
        }
        int div=stoi(s);
        ans+= n/div;
        cout<<ans<<endl;
    }
   
    return 0;
}