#include <iostream>
#include <climits>
using namespace std;
int main()
{
    cout<<" **";
    int n;
    cin>>n;
    cout<<"-*";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"##";    
    long long int N=1e6+2;
    int idx[N];
    cout<<"##";
    for(int i=0;i<N;i++){
        idx[i]=-1;
    }
    int minindex =INT_MAX;
    cout<<"##";
    for(int i=0;i<n;i++){
        if(idx[arr[i]]!=(-1)){
            minindex=min(minindex,idx[arr[i]]);
        }
        else
            idx[arr[i]]=i;
            cout<<"llp";
    }
    if(minindex==INT_MAX){
        cout<<"No repeating unit";
    }
    else
    {
        cout<<minindex+1;
    }

    cout<<"&&";
    return 0;
}