#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef long long int ll;
ll ans[1000001];
void solve()
{
    int k;
    cin >> k;
    int res = 0;
    set<int, greater<int>> v;
    int a = 4 * k + 1;
    res += a;

    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            v.insert(i);
            v.insert(a / i);
        }
    }
    // for (int x : v)
    //     cout << x << endl;
    int l = 2 * k - 1;
    int b;
    int ct = 0; 
    for(int x:v){
        b=(l/x);
    }
    res += (l - ct);

    // int flag=1;
    // for(int j=3;j<(a);j+=2){
    // 	flag=1;
    //     for(int x:v){
    //         if(j%x==0){
    //             res+=x;
    //             flag=0;
    //             break;
    //         }
    //     }
    //     if(flag){
    //         res+=1;
    //     }
    // }
    cout << res << endl;
}

int main()
{

    int tc = 1;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}