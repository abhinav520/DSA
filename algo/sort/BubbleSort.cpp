#include <iostream>
using namespace std;
void print(int n, int arr[]){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int n, int arr[]){
    int flag=0;
    for(int i=0;i<n-1;i++){
        for(int j=1;j<n-i;j++){
            if(arr[j-1]>arr[j]){
                swap(arr[j-1],arr[j]);
                flag=1;
            }
        }
        // print(n,arr);
        if(flag==0) break;   //means list is already sorted
    }
}


int main()
{
    int n;
    cout<<"Enter size of array : "; 
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        // cout<<"Enter value of array at index"<<i<<" : ";
        cin>>arr[i];
    }
    bubbleSort(n,arr);
    print(n,arr);
    return 0;
}