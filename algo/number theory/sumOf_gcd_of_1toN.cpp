// ∑gcd(i,N) (i from 1 to n)
//brute force
//for(int i=1;i<=n;i++){
//     res+=gcd(i,N);  //res=0(initially)
// }
//Question: find optimised approach - q queries in O(q*sqrt(n)).
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

#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef long long int ll;
int *phi =new int[1000001];
//const int m = 1e6 + 1; //this is constraint n<=m

// int occurance(int d, int n)
// {
//     deb(n / d);
//     deb(phi[n / d]);
//     return phi[n / d];
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     int res = 0;
//     for (int i = 2; i * i < n; i++)
//     {
//         if (n % i == 0)
//         {
//             int d1 = i;
//             deb(d1);
//             int d2 = n / i;
//             deb(d2);
//             res += (d1 * occurance(d1, n));
//             deb(n / d1);
//             deb2(res, i);
//             if (d1 != d2) //in case of perfect square d1=d2
//                 res += (d2 * occurance(d2, n));
//             deb(n / d2);
//             deb2(res, i);
//         }
//     }
//     deb(res);
//     cout << res << endl;
// }

int main()
{
    int tc = 1;
    cin >> tc;
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

    while (tc--)
    {
        int n;
        cin >> n;
        int res = 0;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                int d1 = i;
                //deb(d1);
                int d2 = n / i;
                //deb(d2);
                res += (d1 * phi[n/d1]);
                //deb(n / d1);
                //deb2(res, i);
                if (d1 != d2) //in case of perfect square d1=d2
                    res += (d2 * phi[n/d2]);
                //deb(n / d2);
                //deb2(res, i);
            }
        }
        cout << res << endl;
    }
    delete[] phi;
    
    return 0;
}