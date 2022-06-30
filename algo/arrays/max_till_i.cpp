//max till i
#include <iostream>
using namespace std;
int main(){
    cout<<"Enter size of an array: ";
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"enter value at index "<<i<<": ";
        cin>>arr[i];
    }
    int mx=arr[0];
    for(int i=0;i<n;i++){
        mx=max(mx,arr[i]);
        cout<<mx<<endl;
    }
    return 0;
}