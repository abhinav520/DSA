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
    go{
        int n;
        cin>>n;
        n=(2<<(n-1));
        vector<int> v(n);
        input(v,n);
        sort(begin(v),end(v));
        bool flag=true;
        while(n>1){
            int arr[n/2];
            for(int i=0;i<n;i+=2){
                if((v[i+1]-v[i])>1){
                    cout<<"NO\n";
                    flag=false;
                    break;
                }
                arr[i]=v[i]+v[i+1];
            }
            n/=2;
        }
        if(flag){
            cout<<"YES\n";
        }
    }
    return 0;
}