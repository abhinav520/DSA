//INSERTION SORT-Its like inserting an element in an sorted array
#include <iostream>
using namespace std;
void InsertionSort(int n,int arr[]){
    for(int i=1;i<n;i++){
        int k=i;
        for(int j=i-1;j>=0;j--){
            cout<<arr[j]<<">"<<arr[k]<<endl;
            if(arr[j]>arr[k]){
                int temp=arr[j];
                arr[j]=arr[k];
                arr[k]=temp;
                k--;
            }
            else
                break;                
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
    for(int i=0;i<n;i++){
        cout<<"Enter value at index "<<i<<" :";
        cin>>arr[i];
    }
    InsertionSort(n,arr);
    return 0;
}