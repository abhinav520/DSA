#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ct(ll m)
{
    int count=0;
    while (m > 0)
    {
        m /= 10;
        count++;
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        int count = 0;
        if (n % 2050 != 0)
        {
            cout << -1 << endl;
        }
        else
        {
            //ll m = n;
            // vector<int> vec;
            // while (m > 10000)
            // {
            //     m /= 10;
            //     count++;
            // }
            int count=ct(n)-4;
            ll num = 2050 * (pow(10, count));
            ll ans = 0;
            while (n > 10000)
            {
                n -= num;
                
                count=ct(n)-4;
                num = 2050 * (pow(10, count));
                if(num>count){num/=10;}
                ans++;
            }
            ans+=(n/2050);
            cout << ans << endl;
        }
    }
    return 0;
}