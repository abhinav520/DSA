#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int N=1e6+2, ans=-1;
    bool chk[N];
    for(int i=0;i<N;i++){
        chk[i]=false;
    }
    for(int i=0;i<n;i++){             //present-absent approach
        if(arr[i]>=0){
            chk[arr[i]]=true;
        }       
    }
    for(int i=1;i<N;i++){
        if(chk[i]==false){
            ans=i;
            break;
        }
    }
    cout<<ans;
    return 0;
}