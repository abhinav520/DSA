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



int find(int p){
    if(p==1) return 1;
    int fact=1;
    for(int i=1;i<=p;i++){
        fact*=i;
        if(fact==p){
            return 1;
        }
        else if(fact>p){
            fact/=i;
            if(p%fact==0) return (i-1);
            int t=p/fact;
            return t+find(p-t*fact);
        }
    }
    return -1;  //just for completness
}

int main()
{
    int p;
    cin>>p;
    int fact=1;
    int index=0;
    cout<<find(p);
    return 0;
}