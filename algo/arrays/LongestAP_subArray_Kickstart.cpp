#include <iostream>
using namespace std;
int main(){
    int n;    //length of an array
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int diff=A[1]-A[0];
    int curr=2, ans=2;
    for(int j=2;j<n;j++){
        if(diff==A[j]-A[j-1]){
            curr++;
        }
        else
        {
            diff=A[j]-A[j-1];
            curr=2;
        }
        ans=max(ans,curr);
    }
    cout<<ans;
    
}