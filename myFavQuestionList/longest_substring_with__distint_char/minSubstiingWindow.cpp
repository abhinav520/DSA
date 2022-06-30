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
/*
1. Use two pointers: start and end to represent a window.
2. Move end to find a valid window.
3. When a valid window is found, move start to find a smaller window.
*/
  string shortestPalindrome(string s)
  {
    string s2 = s;
    reverse(s2.begin(), s2.end());
    int n = s.size(), l;
    for (l = n; l >= 0; l--)
    {
      deb(l);
      deb(s.substr(0, l));
      deb(s2.substr(n - l));
      if (s.substr(0, l) == s2.substr(n - l))
        break;
    }
    return s2.substr(0, n - l) + s;
  }
};

int main()
{
  // fastio;
  go
  {
    string s;
    cin >> s;
    Solution sol;
    // deb(tc);
    cout << sol.shortestPalindrome(s) << endl;
  }
  return 0;
}