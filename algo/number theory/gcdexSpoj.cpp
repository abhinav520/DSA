// ∑gcd(i,N) (i from 1 to n)
//brute force
//for(int i=1;i<=n;i++){
//     res+=gcd(i,N);  //res=0(initially)
// }
//Question: find optimised approach - q queries in O(nlogn+q*sqrt(n)).
/*
    let n=12;
    gcd(1,12)=1;      gcd(7,12)=1; 
    gcd(2,12)=2;      gcd(8,12)=4; 
    gcd(3,12)=3;      gcd(9,12)=3; 
    gcd(4,12)=4;      gcd(10,12)=2;
    gcd(5,12)=1;      gcd(11,12)=1;
    gcd(6,12)=6;      gcd(12,12)=12;
    ∑gcd(i,N)= 1*4 + 2*2 + 3*2 + 4*2 + 6*1 + 12*1 =40 (here 1,2,3,4,6,12 are dividor of n ie 12)
    so our question can also be interpolated as finding how many times divisors of n in gcd of (1 to n) with n occurs.
    or ie how many numbers i (from 1 to n) are there st gcd(i,n)=d (d=divisors)
    here 1 occurs 4 times
         2 occure 2 times
         3 occurs 2 times
         4 occurs 2 times
         6 occurs 1 time
         12 occur 1 time
    ∑(occurance)=(4+2+2+2+1+1)=12(ie n)   

    gcd(xi,N)=d is same as gcd(xi/d,n/d)=1   (remember this technique is only used to reduce (p/q) fraction into its lowest term)
    gcd(xi/d,n/d)=1 means finding phi(n/d) (euler totient eqn)
    1 <= xi <= n  -----  1 <= xi/d <= n/d
    no. of integer having gcd d with n = no of integers coprime with n/d --> can be found by etf
*/

//in below algo TC=O(nlogn+q*sqrt(n))
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef long long int ll;
int phi[1000001];

int main()
{
    for (int i = 0; i < 1e6 + 1; i++)
    {
        phi[i] = i;
    }

    for (int i = 2; i < 1e6 + 1; i++)
    {
        if (phi[i] == i)
            for (int j = i; j < 1e6 + 1; j += i)
            {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
    }

    auto start1 = high_resolution_clock::now();
    ll *arr = new ll[1000001];
    ll *res = new ll[1000001];
    res[0]=0;
    arr[0] = arr[1] = 0;
    for(int i=2;i<1e6+1;i++)
    for(int j=i;j<1e6+1;j+=i)
    {
        arr[j]+=1LL*i*phi[j/i];
    }
    for(int i=1;i<1e6+1;i++){
        res[i]=res[i-1]+arr[i]-i;
    }

    // for (int j = 2; j < 1e6 + 1; j++)
    // {
    //     ll res = 0;
    //     if (phi[j] == (j - 1))    //saving time for prime
    //     {
    //         arr[j] = arr[j - 1] + (j - 1);
    //     }
    //     else
    //     {
    //         for (int i = 1; i * i <= j; i++)
    //         {
    //             if (j % i == 0)
    //             {
    //                 int d1 = i;
    //                 int d2 = j / i;
    //                 int f1 = 0, f2 = 0;
    //                 if (d1 == j)
    //                     f1 = 1;
    //                 if (d2 == j)
    //                     f2 = 1;
    //                 if (f1 == 0)
    //                     res += (1LL * d1 * phi[j / d1]);
    //                 //deb(n / d1);
    //                 //deb2(res, i);
    //                 if (f2 == 0)
    //                     if (d1 != d2) //in case of perfect square d1=d2
    //                         res += (1LL * d2 * phi[j / d2]);
    //                 //deb(n / d2);
    //                 //deb2(res, i);
    //             }
    //         }
    //         arr[j] = arr[j - 1] + res;
    //     }
    // }

    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);
    cout << "Time Taken 2 : " << duration1.count() << endl;
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        cout << res[n] << endl;
    }
    delete[] arr;
    delete[] res;
    return 0;
}