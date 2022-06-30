#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x) 			 cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) 		 cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec) 	 for(int i=0;i<vec.size();i++){ cout<<vec[i]<<" ";} cout<<endl
#define input(vec,n) 	 for(int i=0;i<n;i++){cin>>vec[i];}
#define go 				 int t;cin>>t;while(t--)
#define fastio 			 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;


int main()
{
    int k;cin>>k;
    int ans=0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int l=1;l<=k;l++){
                ans+=__gcd(__gcd(i,j),l);
            }
        }
    }
    cout<<ans;
    return 0;
}