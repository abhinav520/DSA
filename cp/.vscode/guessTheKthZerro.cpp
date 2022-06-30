#include <bits/stdc++.h>
using namespace std;

#define deb(x) 		cout << #x << "=" << x << endl
#define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef long long int ll;
const int m=2*1e5+7;
int arr[m+1];

void solve(int &n)
{
    int k;
    cin>>k;
    if(k==-1){
        exit(0);
    }
    int l=1,r=n;

    while(l<r){
        int mid=(l+r)/2;
        cout<<"? "<<l<<" "<<mid<<endl;
        int reply;
        cin>>reply;
        int zero=(mid-l+1)-reply;
        arr[mid]=zero;
        if(zero>=k){
            r=mid;
        }
        else{
            k-=zero;
            l=mid+1;
        }
    }
    cout<<"! "<<l<<endl;
    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int tc=1;
    cin>>tc;
    memset(arr,-1,sizeof(arr));
    while(tc--){
        solve(n);

    }


    return 0;
}