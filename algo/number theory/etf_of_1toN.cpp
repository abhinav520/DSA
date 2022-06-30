//pre computation
#include <bits/stdc++.h>
using namespace std;

#define deb(x) 		cout << #x << "=" << x << endl
#define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef long long int ll;
const int m=1e6+1; //this is constraint n<=m
int arr[m];

void solve()
{
    for(int i=0;i<m;i++){      //initialistion
        arr[i]=i;
    }
    for(int i=2;i<m;i++){
        if(arr[i]==i){
            for(int j=i;j<m;j+=i){
                arr[j]/=i;
                arr[j]*=(i-1);
            }
        }
    }
}

ll phin(ll n)
{
    ll number = n;
    if (n % 2 == 0)
    {
        number /= 2;
        while (n % 2 == 0)
            n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            number = (number / i * (i - 1));
        }
    }
    if (n > 1)
        number = (number / n * (n - 1));
    return number;
} // O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/
int main()
{
    int tc=1,n;
    //cin>>tc;

    while(tc--){
        solve();
        for(int i=2;i<100;i++)
        cout<<i<<"="<<arr[i]<<endl;
    }

    return 0;
}