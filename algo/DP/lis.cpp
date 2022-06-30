/* lis() returns the length of the longest
increasing subsequence in arr[] of size n */
#include <bits/stdc++.h>
using namespace std;


int lis(int arr[], int n)
{
  int lis[n];

  lis[0] = 1;

  /* Compute optimized LIS values in
     bottom up manner */
  for (int i = 1; i < n; i++)
  {
    lis[i] = 1;
    for (int j = 0; j < i; j++)
      if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
        lis[i] = lis[j] + 1;
  }

  // Return maximum value in lis[]
  return *max_element(lis, lis + n);
}

/******************************************************************************/
// Dynamic Programming Approach of Finding LIS by reducing
// the problem to longest common Subsequence
int lis_usingLcs(int arr[], int n)
{
  vector<int> b;
  set<int> s;

  // setting iterator for set
  set<int>::iterator it;

  // storing unique elements
  for (int i = 0; i < n; i++)
  {
    s.insert(arr[i]);
  }

  // creating sorted vector
  for (it = s.begin(); it != s.end(); it++)
  {
    b.push_back(*it);
  }
  int m = b.size(), i, j;
  int dp[m + 1][n + 1];

  // storing -1 in dp multidimensional array
  for (i = 0; i < m + 1; i++)
  {
    for (j = 0; j < n + 1; j++)
    {
      dp[i][j] = -1;
    }
  }
  // Finding Longest common Subsequence of the two
  // arrays
  for (i = 0; i < m + 1; i++)
  {
    for (j = 0; j < n + 1; j++)
    {
      if (i == 0 || j == 0)
      {
        dp[i][j] = 0;
      }
      else if (arr[j - 1] == b[i - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[m][n];
}
/**********************************************************************************/


int main()
{
  int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Length of lis is %d\n", lis(arr, n));
}

