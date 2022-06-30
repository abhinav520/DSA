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
    // ini(n);
    string s;
    cin>>s;
    int m = s.length();
    int n = s[m-1] - '0';
    if(n&1){
      int f=(s[0]-'0');
      if(f%2==0){
        cout<<1<<endl;
      }
      else{
        bool flag=true;
        for(int i=1;i<m;i++){
          int c=s[i]-'0';
          // deb(c);
          if(c%2==0){
            cout<<2<<endl;
            flag=false;
            break;
          }
        }
        if(flag){
          cout<<-1<<endl;
        }
      }
    }
    else{
      cout<<0<<endl;
    }
  }
  return 0;
}