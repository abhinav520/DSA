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

int main()
{
  int f = 1 + 2 * 7 + 3 * 49;
  ini(n);
  ini(q);
  string s;
  cin >> s;
  // vector<int> h(n + 1 - 2, 0);
  int h[n-1];
  memset(h,0,sizeof(h));
  for (int i = 1; i <= n - 2; i++)
  {
    int g1 = s[i - 1] - 'a' + 1;
    int g2 = s[i] - 'a' + 1;
    int g3 = s[i + 1] - 'a' + 1;
    h[i] = (g1 + g2 * 7 + g3 * 49);
  }

  int ans=0;
  for(int i=1;i<(n-1);i++){
    if(h[i]==f){
      ans++;
    }
  }
  // deb(ans);
  while (q--)
  {
    ini(k);
    char c;
    cin >> c;
    s[k - 1] = c;
    // deb(s);
    for (int i = k; i >= k - 3; i--)
    {
      if (h[i] == f)
      {
        ans-=1;
      }
      int g1 = s[i - 1] - 'a' + 1;
      int g2 = s[i] - 'a' + 1;
      int g3 = s[i + 1] - 'a' + 1;
      h[i] = (g1 + g2 * 7 + g3 * 49);
      if (h[i] == f)
      {
        ans+=1;
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}