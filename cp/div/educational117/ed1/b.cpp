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


int main()
{
  // fastio;
  go{
    ini(n);
    ini(a);
    ini(b);
    if(a<=(n/2+1) && b>=(n/2)){
      if(b>a){
        if ((b - a) >= (n/2)-1){
          cout<<a<<" ";
          int ct=1;
          for(int i=b+1;i<=n;i++){
            cout<<i<<' ';
            ct++;
          }
          int k=a;
          k++;
          while(ct!=(n/2)){
            cout<<k++<<" ";
            ct++;
          }
          cout<<b<<" ";
          ct=1;
          for (int i = a-1; i>0; i--)
          {
            cout << i << ' ';
            ct++;
          }
          while (ct != (n / 2))
          {
            cout << k++ << " ";
            ct++;
          }
          cout<<endl;
        }
        else
        {
          cout << "-1\n";
        }
        // else{
        //   //  if(n-b+a-1 >=(n/2)){

        //   //  }

        // }
      }
      else{
        for(int i=a;i<=n;i++){
          cout<<i<<" ";
        }
        for(int i=b;i>0;i--){
          cout << i << " ";
        }
        cout<<endl;
      }
    }
    else{
      cout<<"-1\n";
    }
  }
  return 0;
}