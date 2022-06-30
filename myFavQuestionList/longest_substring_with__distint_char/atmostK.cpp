#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longKSubstr(string s, int k)
  { // following template
    int mx = -1;
    int n = 0; //unique count
    int j = 0, i = 0;
    int size = s.length();
    int arr[26] = {0};
    while (j < size)
    {
      if (n <= k) //j <= unique count
      {
        int idx = s[j] - 'a';
        if (arr[idx] == 0)
        {
          n++;
        }
        arr[idx]++;
        j++;
      }
      else
      {
        int idx = s[i] - 'a';
        arr[idx]--;
        if (arr[idx] == 0)
        {
          n--;
        }
        i++;
      }
      if (n <= k)
      {
        mx = max(mx, j - i);
      }
    }
    return mx;
  }
};

int main()
{
  string s;
  cin >> s;
  int n;
  cin >> n;
  Solution sol;
  cout << sol.longKSubstr(s, n) << endl;
  return 0;
}