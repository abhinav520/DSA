#include <bits/stdc++.h>
using namespace std;

#define deb(x) 		cout << #x << "=" << x << endl
#define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef long long int ll;


void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int dis=0;
    for(int i=1;i<s.length();i++){
        dis+=((s[i-1]+s[i])%2)?1:2;
    }
    deb(dis);
    int v[k];
    for(int i=0;i<k;i++){
        cin>>v[i];
    }
    for(int i=0;i<k;i++){
        if(v[i]!=n){
            if((s[v[i]-1]+s[v[i]])%2){
                dis++;
            }
            else{
                dis--;
            }
        }
        if(v[i]!=1){
            if((s[v[i]-1]+s[v[i]-2])%2){
                dis++;
            }
            else{
                dis--;
            }
        }
        // if(v[i]==1){
        //     if((v[i]+v[i+1])%2){
        //         dis++;
        //     }
        //     else{
        //         dis--;
        //     }
        // }
        // else if(v[i]==n){
        //     if((v[i]+v[i-1])%2){
        //         dis++;
        //     }
        //     else{
        //         dis--;
        //     }
        // }
        // else{
        //     if((v[i]+v[i+1])%2){
        //         dis++;
        //     }
        //     else{
        //         dis--;
        //     }

        //     if((v[i]+v[i-1])%2){
        //         dis++;
        //     }
        //     else{
        //         dis--;
        //     }
        // }
        s[v[i]-1]=(s[v[i]-1]=='0')?'1':'0';
        cout<<dis<<endl;
    }
}


int main()
{
    int tc=1;
    cin>>tc;

    while(tc--){
        solve();
    }

    return 0;
}