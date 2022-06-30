//Finding Max and Min element
#include <iostream>
#include <climits>
using namespace std;
int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter value at "<<i<<" index :";
        cin>>arr[i];
    }
    // int max= arr[0];
    // int min=arr[0];
    int maxNo=INT_MIN;
    int minNo=INT_MAX;
    for(int i=0;i<n;i++){
        // if(arr[i]<min){
        //     min=arr[i];
        // }
        maxNo=max(arr[i],maxNo);
        minNo=min(arr[i],minNo);
        // else if(arr[i]>max){
        //     max=arr[i];
        // }
    }
    cout<<"The max value is "<<maxNo;
    cout<<"\nThe min value is "<<minNo;

    return 0;
}