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
    fastio;
    int t;
    cin>>t;
    while(t--){
        int x,p;
        
        cout<<1<<" "<<x<<endl;
        ll recieved;
        cin>>recieved;
        if(recieved==-1) return 0;
        ll y=x*x;
        //y==recieved (mod p)
        

        cout<<2<<" "<<p<<endl;
        string str;
        cin>>str;
        if(str=="No") return 0;
    }
    
    return 0;
}