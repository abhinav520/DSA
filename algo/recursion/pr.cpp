// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
  int id;     // Job Id
  int dead;   // Deadline of job
  int profit; // Profit if job is over before or on deadline
};

// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
public:
  static bool cmp(Job j1, Job j2)
  {
    return j1.profit > j2.profit;
  }
  // Function to find the maximum profit and the number of jobs done.
  vector<int> JobScheduling(Job arr[], int n)
  {
    // for(int i=0;i<n;i++){
    //     cout<<arr[i].id<<" "<<arr[i].dead<<" "<<arr[i].profit<<endl;
    // }
    sort(arr, arr + n, cmp);
    //  cout<<"******************"<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<arr[i].id<<" "<<arr[i].dead<<" "<<arr[i].profit<<endl;
    // }
    int lastDeadline = 0;
    for (int i = 0; i < n; i++)
    {
      lastDeadline = max(lastDeadline, arr[i].dead);
    }
    // cout<<lastDeadline<<endl;
    int v[lastDeadline + 1];
    memset(v, 0, sizeof(v));
    int kamai = 0, cnt = 0;
    for (int i = 0; i < n && cnt < lastDeadline; i++)
    {
      if (v[arr[i].dead] == 0)
      {
        kamai += arr[i].profit;
        v[arr[i].dead] = 1;
        cnt++;
      }
      else
      {
        int j = arr[i].dead - 1;
        while (v[j] != 0 && j >= 1)
        {
          j--;
        }
        if (j >= 1)
        {
          kamai += arr[i].profit;
          v[j] = 1;
          cnt++;
        }
      }
    }
    vector<int> ans = {cnt, kamai};
    return ans;
  }
};

// { Driver Code Starts.
// Driver program to test methods
int main()
{
  int t;
  // testcases
  cin >> t;

  while (t--)
  {
    int n;

    // size of array
    cin >> n;
    Job arr[n];

    // adding id, deadline, profit
    for (int i = 0; i < n; i++)
    {
      int x, y, z;
      cin >> x >> y >> z;
      arr[i].id = x;
      arr[i].dead = y;
      arr[i].profit = z;
    }
    Solution ob;
    // function call
    vector<int> ans = ob.JobScheduling(arr, n);
    cout << ans[0] << " " << ans[1] << endl;
  }
  return 0;
}

// } Driver Code Ends