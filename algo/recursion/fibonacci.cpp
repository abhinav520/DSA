#include <iostream>
using namespace std;
int fib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int first = 0, sec = 1, series = 0;
    for(int i = 2; i <= n; i++)
    {
        series = first + sec;
        first = sec;
        sec = series;
    }
    return series;
}
//recursive solution --> inefficient using same thing multiple times like for n=3 calculating fib(1) fib(0) fib(2) multiple times that to thru recursion
int rfib(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return rfib(n - 1) + rfib(n - 2);
}
//--> Effeicient approach is used to memorize the result (by storing in array) that already have been evaluated and using it latter when required.
//There is 2 methods-1)Tabulation (bottom up approach)
//                   2)Memoization (top down approach)

//Using memoization in 1D
int f[100];
int mfib(int n)
{
    if (n <= 1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if ((n - 2) != f[n - 2])
        {
            f[n - 2] = mfib(n - 2);
        }
        if (f[n - 1] != (n - 1))
        {
            f[n - 1] = mfib(n - 1);
        }
        return f[n - 2] + f[n - 1];
    }
}
int main()
{
    int n;
    cout << "Enter the term number of fibonacci series: ";
    cin >> n;
    cout << fib(n);
    return 0;
}