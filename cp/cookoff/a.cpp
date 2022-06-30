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

ll solve(int x, int y){
    if((x&1) && (y&1)){
        if(__gcd(x,(y+1))>1 || __gcd((x+1),y)>1) return 1;
        return 2;
    }
    return 1;
}

int main()
{
    go{
        int x,y;
        cin>>x>>y;
        if(__gcd(x,y)>1){
            cout<<0<<endl;
        }
        else
            cout<<solve(x,y)<<endl;
    }
    return 0;
}