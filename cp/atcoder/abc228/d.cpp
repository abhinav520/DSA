#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x) 			 cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) 		 cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec,n) 	 for(int i=0;i<n;i++){ cout<<vec[i]<<" ";} cout<<endl
#define input(vec,n) 	 for(int i=0;i<n;i++){cin>>vec[i];}
#define go 				 int tc;cin>>tc;while(tc--)
#define fastio 			 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ini(_n) int _n;cin>>_n;
#define inl(_l) ll _l;cin>>_l;
typedef long long int ll;

const int n=1<<20;
int arr[n];

int main()
{
  memset(arr,-1,sizeof(arr));
  go{
    ini(t);inl(x);
    if(t==1){
      int m=x%n;
      while (arr[m]!=-1){
        m++;
        if(m>=n){
          m=0;
        }
      }
      arr[m] = x;
    }
    else{
      cout<<arr[x%n]<<endl;
    }

  }
  return 0;
}