#include <bits/stdc++.h>
using namespace std;

#define deb(x) 		cout << #x << "=" << x << endl
#define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef long long int ll;
const int m=1000003;
int pri[m];

int main()
{
    int l,r;
    cin>>l>>r;
    for(int i=2;i<m;i++){
        if(pri[i]!=0){
            continue;
        }

    } 
    map<int,vector<int>> mp;
    // for(int i=l;i<=r;i++){
    //     mp[i]={0};
    // }  
    for(int i=2;i*i<=r;i++){
        for(int j=i;j<=r;j+=2)
            if(j%i==0 && i!=j && i/j!=0)
            mp[j].push_back(i)
    }
    
    return 0;
}