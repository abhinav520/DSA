#include <iostream>
// int pow(int m, int n)
// {
//     if (n == 1)
//     {
//         return m;
//     }
//     return m * pow(m, (n - 1));
// }

//-->efficient algo
int power(int m, int n)
{
    if (n == 1)
    {
        return m;
    }
    if (n % 2 == 0)
    {
        return power(m * m, n / 2);
    }
    else
    {
        return m * power(m * m, (n - 1) / 2);
    }
}

using namespace std;
int main()
{
    int n,m;
    cout<<"Enter base and exponent (m n): ";
    cin>>m>>n;
    cout<<m<<"^"<<n<<"="<<power(m,n)<<endl;
    // cout<<m<<"^"<<n<<"="<<pow(m,n);
    return 0;
}