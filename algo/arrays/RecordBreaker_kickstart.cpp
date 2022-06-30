#include <iostream>
using namespace std;
int main(){
    int tc,temp;
    cin>>tc;
    temp=tc;
    int arr[temp];
    while(tc>0){
        int count=0;
        int N;
        cin>>N;
        int A[N+1];
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        A[N]=-1;
        // if(N==1){
        //     count++;
        // }
        int mx=-1;
        for(int i=0;i<N;i++){
            if(A[i]>mx){
                mx=A[i];
                if(A[i]>A[i+1]){
                    count++;
                }
            }           
        }
        arr[temp-tc]=count;
        tc--;
    }
    for(int i=0;i<temp;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}