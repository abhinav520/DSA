//SELECTION SORT
#include <iostream>
#include <climits>
using namespace std;
void selectionSort(int n, int arr[]){
    int minindex = 0;
    for(int k=0;k<n-1;k++){
        int minNo=arr[k];
        minindex = k;
        for(int j=k+1;j<n;j++){            
            if(arr[j] < minNo) {
                minindex = j;
                minNo = arr[minindex];                
            }                     
        }
        
        arr[minindex] = arr[k];
        arr[k]=minNo;
        
    }
    for(int k=0;k<n;k++){
        cout<<arr[k]<<" ";
    }
}
int main(){
    int n;
    cout<<"Enter size of array : "; 
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        // cout<<"Enter value of array at index"<<i<<" : ";
        cin>>arr[i];
    }
    selectionSort(n,arr);
    return 0;
}