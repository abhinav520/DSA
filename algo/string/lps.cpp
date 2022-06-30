//Pattern searching algorithm-Kruth Moris Prat KMP algorithm
// longest prefix which is also a suffix
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void computeLPA(string &s, int *lps, int n)
  {
    lps[0] = 0;
    int i = 1, len = 0;
    while (i < n)
    {
      if (s[i] == s[len])
      {
        len++;
        lps[i] = len;
        i++;
      }
      else
      { // (s[i] != s[len])
        // This is tricky. Consider the example.
        // AAACAAAA and i = 7. The idea is similar
        // to search step.
        if (len != 0)
        {
          len = lps[len - 1];   // most difficult part to understand
        }
        else
        {
          lps[i] = 0;
          i++;
        }
      }
    }
  }
  int kmp(string haystack, string needle)
  {
    int n = haystack.length();
    int m = needle.length();
    if (m == 0)
      return 0;

    int lps[m];
    computeLPA(needle, lps, m);
    int i = 0, j = 0;
    while (i < n)
    {
      if (haystack[i] == needle[j])
      {
        i++;
        j++;
      }
      if (j == m)
        return (i - j);
      else if (i < n && needle[j] != haystack[i])
      {
        if (j != 0)
          j = lps[j - 1];
        else
        {
          i++;
        }
      }
    }
    return -1;
  }
};


int main()
{

  // ios_base::sync_with_stdio(0);
  // cin.tie(NULL);
  // cout.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    string str;
    cin >> str;
    string pat;
    cin >> pat;

    Solution ob;

    cout << ob.kmp(str,pat) << "\n";
  }

  return 0;
}
