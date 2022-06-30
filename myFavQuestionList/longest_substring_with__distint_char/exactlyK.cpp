//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

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
  int longestKSubstrIIattempt(string s,int k){  // following template
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
      if (k == n)
      {
        mx = max(mx, j - i);
      }
    }
    return mx;
  }

  int longestKSubstr(string s, int k)  //my head's hit and trial method
  {
    int curr = 0;
    int max = 0;
    int n = 0;
    int j = 0;
    int size = s.length();
    unordered_map<char, int> mp;
    for (int i = 0; i < size; i++)
    {
      if (n > k)
      {
        max = ((curr - 1) > max) ? (curr - 1) : max;
        while (n != k)
        {
          char c = s[j++];
          mp[c]--;
          if (mp[c] == 0)
            n--;
          curr--;
        }
        i--;
      }
      else
      {
        char c = s[i];
        if (mp.find(c) == mp.end() || mp[c] == 0)
        {
          n++;
        }
        mp[c]++;
        curr++;
      }
    }
    if (n > k)
    {
      max = ((curr - 1) > max) ? (curr - 1) : max;
    }
    else
      max = ((curr) > max) ? (curr) : max;

    return (n >= k) ? max : -1;
  }
};

int main()
{
  // fastio;
  ini(k);
  string s;
  cin >> s;
  Solution sol;
  // cout << sol.longestKSubstr(s, k) << endl;
  cout << sol.longestKSubstrIIattempt(s, k) << endl;
  return 0;
}