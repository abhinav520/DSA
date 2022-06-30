#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int arr[N];
int rec(vector<int> &h, int i, int n, long long cost){
  if(i==n){
    return cost;
  }
  int a=INT_MAX,b=INT_MAX;
  if(i+2<=n){
    if(arr[i+2]==-1)
      b = rec(h, i + 2, n, cost + abs(h[i + 2] - h[i]));
    else b=arr[i+2];
  }
  if(i+1<=n){
    if (arr[i + 1] == -1)
      a = rec(h, i + 1, n, cost + abs(h[i + 1] - h[i]));
    else a = arr[i + 1];
  }
  return min(a,b);
}

int main()
{
  memset(arr,-1,sizeof(arr));
  int n,k;
  cin>>n>>k;
  vector<int> h(n+1);
  for(int i=1;i<=n;i++){
    cin>>h[i];
  }
  int i=n-1;
  for(;i>=max(1,n-k);i--){
    arr[i]=abs(h[n]-h[i]);
  }
  for(;i>=1;i--){
    arr[i]=arr[i+1]+abs(h[i+1]-h[i]);
    for(int j=2;j<=k;j++){
      arr[i] = min(arr[i], arr[i + j] + abs(h[i + j] - h[i]));
    }
  }
  cout<<arr[1]<<endl;
  // cout<<rec(h,1,n,0);
  return 0;
}