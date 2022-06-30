#include <bits/stdc++.h>
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int a, int lim){
    uniform_int_distribution<int> uid(a, lim );
    return uid(rang);
}


struct testcase
{
    int x,y;
};
struct ans{
    int a,b,res;
};
int randomNumber(int a, int b)
{
    return a + (rand() % b);
}
testcase generateTestCase()
{
    testcase randomTest;
    randomTest.x = rng(2,10);
    randomTest.y = rng(1,5);
    return randomTest;
}
ans bruteForce(testcase T)
{
    int n, m;
    // cin >> n >> m;
    n=T.x;
    m=T.y;
    ans an;
    an.a=n;an.b=m;
    an.res = n - 1;
    int a, b;
    for (int i = 2; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if ((m % i) % j == (m % j) % i)
            {
                an.res++;
            }
        }
    }
    return an;
}
ans optimizedSolution(testcase T)
{
    int n, m;
    // cin >> n >> m;
    n=T.x;
    m=T.y;
    ans an;
    an.a=n;an.b=m;
    an.res = n - 1;
    int k, d;
    // if(m==1){
    //     an.res=0;
    //     for(int i=2;)
    // }
    for (int i = 3; i <= n; i++)
    {
        k = m - m % i;
        if(k==0 && m==1) an.res+=n-(i-1);
        else if(k==0 && m!=1) an.res+=(i-1);
        for (int j = 2; j < i && j * j <= k; j++)
        {
            if (k % j == 0)
            {
                if ((k / j) != j && (k / j) < i)
                    an.res += 2;
                else
                    an.res += 1;
            }
        }
    }
    return an;
}

void debugger()
{
    testcase random = generateTestCase();
    ans ans1 = bruteForce(random);
    ans ans2 = optimizedSolution(random);
    //cout<<ans1<<" "<<ans2<<endl;
    if (ans1.res != ans2.res)
    {
        cout << "wrong ans"<<endl;
        cout<<ans1.a<<" "<<ans1.b<<" "<<"correct ans= "<<ans1.res<<endl;
        cout<< ans2.a<<" "<<ans2.b<<" "<<"your ans="<<ans2.res<<endl;
        return;
    }
    cout<<"AC\n";
}

void solve1()
{
    int n, m;
    cin >> n >> m;
    int ans = n - 1;
    int a, b;
    for (int i = 2; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if ((m % i) % j == (m % j) % i)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}

void solve2()
{
    int n, m;
    cin >> n >> m;
    int ans = n - 1;
    int k, d;
    for (int i = 3; i <= n; i++)
    {
        k = m - m % i;
        for (int j = 2; j < i && j * j <= k; j++)
        {
            if (k % j == 0)
            {
                if ((k / j) != j && (k / j) < i)
                    ans += 2;
                else
                    ans += 1;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    int t=1;
    cin >> t;
    while (t--)
        // int bf= bruteForce();
        // int of= optimizedSolution();
        debugger();
    return 0;
}