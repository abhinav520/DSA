//QUICK SORT
#include <iostream>
using namespace std;
void BubbleSort(int n,int arr[]){
    for(int i=0;i<n;i++){
        for(int j=0;j<(n-i);j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    for(int i=1;i<=n;i++){
        cout<<"Enter value at index "<<i<<" :";
        cin>>arr[i];
    }
    BubbleSort(n,arr);
    return 0;
}