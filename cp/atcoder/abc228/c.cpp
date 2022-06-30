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
  int n,k;
  cin>>n>>k;
  vector<pair<int,int>> v(n);
  for(int i=0;i<n;i++){
    int sum=0;
    for (int j = 1; j <= 3; j++){
      int b;
      cin>>b;
      sum+=b;
    }
    v[i]={sum,i};
  }
  sort(v.begin(),v.end());
  
  int arr[n];
  int mx=v[n-k].first;
  for (int i = 0; i < n; i++)
  {
    if(mx-v[i].first<=300){
      arr[v[i].second] =1;
    }
    else{
      arr[v[i].second] = 0;
    }
  }
  for(int i=0;i<n;i++){
    if(arr[i]){
      cout << "Yes\n";
    }
    else{
      cout << "No\n";
    }
  }
  return 0;
}