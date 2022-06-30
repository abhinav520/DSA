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
int a[17][17];

void solve(){
  ini(n);
  vector<int> vec(1 + n);
  int mx=0; int mi=0;
  for (int i = 1; i < 1 + n; i++)
  {
    cin >> vec[i];
    if (a[vec[i]][0] % 2 == 1)
      if (a[vec[i]][0]>mx){
        mx = a[vec[i]][0];
        mi=i;
      }
  }
  auto it = vec.begin()+mi;
  if (n == 1)
  {
    cout << vec[1] << endl;
    return;
  }
  ll b=a[vec[mi]][1];
  ll ans = mx;
  ll c=0;
  vec.erase(it);
  for(int i=1;i<n;i++){
    while(vec[i]%2==0){
      vec[i]/=2;
      b++;
    }
    c+=vec[i];
  }
  while (b--)
  {
    ans *= 2;
  }
  cout << c + ans << endl;
  
}


int main()
{
  fastio;
  for(int i=1;i<=16;i++){
    if(i%2==0){
      int g=0;
      int j=i;
      while(j%2==0){
        g++;
        j/=2;
      }
      a[i][0]=j;
      a[i][1]=g;
    }else{
      a[i][0]=i;
      a[i][1]=0;      
    }
  }
  go{
    solve();
  }
  return 0;
}