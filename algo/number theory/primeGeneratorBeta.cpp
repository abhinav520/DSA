//https://www.spoj.com/problems/PRIME1/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int b = 100001;
ll prime[b];


//primeme no in range m to n (both inclusive) using segmented sieve
//useful in case of large numbers (say 1e12) here in spojprimeme1 constraints are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000)


void solve()
{
    int m, n;
    cin >> m >> n;
    if(m==1) m++;
    ll arr[n - m + 1];
    for (int i = 0; i <= n - m; i++)
    {
        arr[i] = m + i;
    }

    int k=1;
    while(1LL*prime[k]*prime[k]<=n){
        int i=(m/prime[k])*prime[k];
        if(i<m) i+=prime[k];
        for(;i<=n;i+=prime[k]){
            if(arr[i-m]==i)
            arr[i-m]=prime[k];
        }
        k++;
    }


    for (int i = 0; i <= n - m; i++)
    {
        if (arr[i] == m + i)
        {
            cout << arr[i] << endl;
        }
    }
}

int main()
{
    int tc = 1;
    cin >> tc;
    for (int i = 2; i < b; i++)
    {
        if (prime[i] == 0)
            for (ll j = 1ll * i * i; j < b; j += i)
            {
                prime[j] = 1;
            }
    }
   
    int g = 1;
    for (int i = 2; i < b; i++)
    {
        if (prime[i] == 0)
        {
            prime[g++] = i;
        }
    }
    while (tc--)
    {
        solve();
        cout<<endl;
    }

    return 0;
}