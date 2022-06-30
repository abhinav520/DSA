#include <iostream>
using namespace std;
void sievePrime(int n);
int main()
{
    int n;
    cin >> n;
    sievePrime(n);
    return 0;
}
void sievePrime(int n)
{
    int prime[n + 1] = {0};
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                // if(prime[j]==0)
                    prime[j] = i;
            }
        }
    }
    int count=0;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            cout << i << " ";
            count++;
        }
    }
    cout<<endl<<count;
}
