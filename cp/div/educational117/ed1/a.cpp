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
    ini(x);
    ini(y);
    int ab=abs(x)+abs(y);
    if(ab&1){
      cout<<"-1 -1\n";
    }
    else{
      ab/=2;
      int a=min(x,y);
      ab-=a;
      if(ab<=max(x,y)){
        if(x<y){
          cout<<a<<" "<<ab<<endl;
        }
        else{
          cout<<ab<<" "<<a<<endl;
        }
      }
      else{
        cout << "-1 -1\n";
      }
    }
  }
  return 0;
}