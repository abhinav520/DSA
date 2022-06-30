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
        string s;
        cin>>s;
        vector<int> a,b;
        int j=s.size()-1;
        int i=0;
        bool f1=false,f2=false;

        while(i<=j){
            while(i<=j){
                if (s[i] == '1')
                {
                    a.push_back(i + 1);
                    f1 = true;
                    i++;
                    break;
                }
                i++;
            }
            while(i<=j){
                if(s[j]=='0'){
                    b.push_back(j+1);
                    f2=true;
                    j--;
                    break;
                }
                j--;
            }
            
        }

        int m=(f1 && f2)?1:0;
        cout<<m<<endl;
        if(m!=0){
            cout<<(a.size()+b.size())<<" ";
            for(int x:a) cout<<x<<" ";
            // for(int x:b) cout<<x<<" ";
            for (auto it = b.rbegin(); it != b.rend(); it++)
            {
                cout << *it <<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}