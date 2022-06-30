#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x) 			 cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) 		 cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec,n) 	 for(int i=0;i<n;i++){ cout<<vec[i]<<" ";} cout<<endl
#define input(vec,n) 	 for(int i=0;i<n;i++){cin>>vec[i];}
#define go 				 int t;cin>>t;while(t--)
#define fastio 			 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;


int main()
{
  int n,x;
  cin>>n>>x;
  vector<int> v(n);
  input(v,n);
  int arr[n+1];
  memset(arr,0,sizeof(arr));
  int cnt=0;
  arr[x]=1;
  cnt++;
  int i=v[x-1];

  while(arr[i]!=1){
    cnt++;
    arr[i]=1;
    i=v[i-1];
  }
  cout<<cnt;
  return 0;
}