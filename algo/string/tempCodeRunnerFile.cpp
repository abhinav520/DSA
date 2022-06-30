#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x) 					 cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) 			 cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec,s,n)  for(int i=s;i<s+n;i++){ cout<<vec[i]<<" ";} cout<<endl
#define input(vec,s,n) 	 vector<int> vec(s+n);for(int i=s;i<s+n;i++){cin>>vec[i];}
#define ini(_n) 				 int _n;cin>>_n;
#define inl(_n) 				 ll _n;cin>>_n;
#define go 							 int tc;cin>>tc;while(tc--)
#define fastio 					 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;

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
    {
      if (len != 0)
      {
        len = lps[len - 1]; // most difficult part to understand
      }
      else
      {
        lps[i] = 0;
        i++;
      }
    }
  }
}

void solve(){
  inl(m);
  string needle,haystack;
  cin>>needle>>haystack;
  int n = haystack.length();
  // int m = needle.length();
  if (m == 0)
    {cout<<endl;
    return;}

  int lps[m];
  computeLPA(needle, lps, m);
  int i = 0, j = 0;
  bool flag=true;
  while (i < n)
  {
    if (haystack[i] == needle[j])
    {
      i++;
      j++;
    }
    if (j == m){
      cout<< (i - j)<<endl;
      j = lps[j - 1];
      flag=false;
    }
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
  if(flag) cout<<endl;

}


int main()
{
  // fastio;
  go{
    deb(tc);
    solve();
    cout<<endl;
  }
  return 0;
}