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
    fastio;
    go{
        int n;
        cin>>n;
        vector<int> v(n);
        int mn=INT_MAX;
        int cnt_mn=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            mn=min(mn,v[i]);
        }
        int sc=INT_MAX;
        // int cnt_sc=0;
        for(int i=0;i<n;i++){
            if(sc>v[i] && v[i]!=mn){
                sc=v[i];
            }
        }
        int ans=0;
        bool flag=false;
        for(int i=0;i<n;i++){
            if(v[i]==mn) cnt_mn++;
            if(mn*2==v[i]) {
                ans=n;
                flag=true;
                break;
            }
            // if(v[i]==sc) cnt_sc++;
        }

        if(!flag){
            if(sc-mn==1 || sc==mn*2){
                ans=n;
            }
            else{
                ans=n-cnt_mn;
            }
        }
        
        cout<<ans<<endl;
    }
    return 0;
}
