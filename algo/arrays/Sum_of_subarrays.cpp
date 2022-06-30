//Sum of subarrays
#include <iostream>
using namespace std;
int main(){
    int n;
    // cout<<"Enter the size of an array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        // cout<<"Enter the value at index "<<i<<" :";
        cin>>arr[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            cout<<sum<<endl;
        }
    }
    return 0;
}