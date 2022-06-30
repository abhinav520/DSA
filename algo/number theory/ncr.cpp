/*
The formula to find the entry of an element in the nth row and kth column of a pascal’s triangle is given by:
(nCk). The elements of the following rows and columns can be found using the formula given below.
(nCk)=(n−1Ck−1)+(n−1Ck)   --> This is recursion
Here, n is any non-negative integer and 0 ≤ k ≤ n.
The above notation can be written as:
(nCk) (i.e., n choose k) = C(n, k) = nCk = n!/[k!(n – k)!]
This pattern of getting binomial coefficients is called Pascal’s rule.
*/
#include <iostream>
#include <cstring>
using namespace std;

// int combination_ncr(int n, int r)
// {
//   if (r == 0 || n == r)
//   {
//     return 1;
//   }
//   return combination_ncr(n - 1, r - 1) + combination_ncr(n - 1, r); // has overlapping subproblems-->goto DP
// }

// int combination_ncr_dp(int n, int r)
// {
//   int arr[n + 1][n + 1];
//   memset(arr, 0, sizeof(arr));
//   for (int i = 0; i <= n; i++)
//   { // initialization
//     arr[i][0] = 1;
//     arr[i][i] = 1;
//   }
//   for (int i = 2; i <= n; i++)
//   {
//     for (int j = 1; j < i; j++)
//     {
//       arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
//     }
//   }
//   return arr[n][r];
// }
int ncr(int n, int r)
{
  if (r > n - r)
    r = n - r;
  int arr[r + 1] = {0};
  arr[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = min(i, r); j > 0; j--)
    {
      arr[j] = arr[j - 1] + arr[j]; // nCj = (n-1)Cj + (n-1)C(j-1);
    }
  }
  return arr[r];
}

// int factorial(int n)
// {
//   if (n == 1)
//   {
//     return 1;
//   }
//   return n * factorial(n - 1);
// }
// int combinationUsingFactorial(int n, int r)
// {
//   return (factorial(n) / (factorial(n - r) * factorial(r)));
// }
int main()
{
  int n, r;
  cout << "Enter n: ";
  cin >> n;
  cout << "Enter r: ";
  cin >> r;
  // cout<<"The value of C("<<n<<","<<r<<") using Pascal triangle is "<<combination_ncr(n,r)<<endl;
  cout << "The value of C(" << n << "," << r << ") using Dp and pascal triangle is " << ncr(n, r) << endl;
  // cout<<"The value of C("<<n<<","<<r<<") using factorial is UsingFactorial "<<combinationUsingFactorial(n,r)<<endl;
  return 0;
}