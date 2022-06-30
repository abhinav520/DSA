#include <bits/stdc++.h>
using namespace std;

#define deb(x) 		cout << #x << "=" << x << endl
#define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef long long int ll;
const int m=1e7;
int prime[m+1];


int main()
{
    for(int i=2;i<=m;i++){
        prime[i]=1;
    }
    for (int i = 2; i <= m; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = 2 * i; j <= m; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    for(int i=3;i<=m;i++){
        if(prime[i]==1){
            if(2*i<=m)
            prime[2*i]=-1;
        }
    }
    for(int i=0;i<=20;i++){
        cout<<prime[i]<<" ";
    }
    cout<<endl;
    for(int i=2;i<=m;i++){
        prime[i]+=prime[i-1];
    }

    int tc=1;
    //cin>>tc;

    while(tc--){
        //int n; cin>>n;
        for(int i=2;i<=30;i++)
        cout<<prime[i]<<" ";
    }

    return 0;
}