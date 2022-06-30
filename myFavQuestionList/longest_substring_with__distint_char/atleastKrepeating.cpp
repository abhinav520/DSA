//https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x) 					 cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) 			 cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec,n) 	 for(int i=0;i<n;i++){ cout<<vec[i]<<" ";} cout<<endl
#define input(vec,n) 		 for(int i=0;i<n;i++){cin>>vec[i];}
#define ini(_n) 				 int _n;cin>>_n;
#define inl(_n) 				 ll _n;cin>>_n;
#define go 							 int tc;cin>>tc;while(tc--)
#define fastio 					 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;

class Solution
{
public:
  //divide and conquer
  int solve(string &s, int l, int r, int k)
  {
    if (l > r)
      return 0;
    int n = s.length();
    if (k == 1)
      return n;
    if (k > n)
      return 0;
    // if(s.length()==1){
    //     return (k==1);
    // }
    int arr[26] = {0};
    for (int i = l; i <= r; i++)
    {
      int ascii = s[i] - 'a';
      arr[ascii]++;
    }
    int curr = 0, mx = 0;
    int i = l;
    bool flag = true;
    int a = l;
    while (i <= r)
    {
      if (arr[s[i] - 'a'] < k)
      {
        int submx = solve(s, a, i - 1, k);
        a = i + 1;
        mx = max(mx, submx);
        flag = false;
      }
      else
      {
        curr++;
      }
      i++;
    }
    if (flag)
      mx = max(mx, curr);
    else
      mx = max(mx, solve(s, a, r, k));
    return mx;
  }

  //two pointer approach
  int solveTwoPointer(string s, int k)
  {
    int mx = 0;
    int n = s.length();
    int arr[26];
    for (int h = 0; h < 26; h++)
    {
      memset(arr, 0, sizeof(arr));
      int j = 0, i = 0;
      int unique = 0;
      int atLeastKct = 0;
      while (j < n)
      {
        if (unique <= h)
        {
          int idx = s[j] - 'a';
          if (arr[idx] == 0)
          {
            unique++;
          }
          arr[idx]++;
          if (arr[idx] == k)
          {
            atLeastKct++;
          }
          j++;
        }
        else
        {
          int idx = s[i] - 'a';
          if (arr[idx] == k)
          {
            atLeastKct--;
          }
          arr[idx]--;
          if (arr[idx] == 0)
          {
            unique--;
          }
          i++;
        }
        if (h == unique && unique == atLeastKct)
        {
          mx = max(mx, j - i);
        }
      }
    }
    return mx;
  }
  int longestSubstring(string s, int k)
  {
    // return solve(s,0,s.length()-1,k);
    return solveTwoPointer(s, k);
  }
};


int main()
{
  // fastio;
  ini(k);
  string s;
  cin >> s;
  Solution sol;
  cout << sol.longestSubstring(s, k) << endl;
  return 0;
}