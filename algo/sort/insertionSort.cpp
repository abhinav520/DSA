#include <iostream>
using namespace std;
void print(int n, int arr[]){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int n, int arr[]){
    for(int i=1;i<n;i++){
        // cout<<"\n"<<(i-1)<<"th sorted\n";
        for(int j=i;j>=1;j--){
            if(arr[j-1]>arr[j]) swap(arr[j-1],arr[j]);
            // print(n, arr);
        }
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
    cout<<endl;
    insertionSort(n,arr);
    print(n,arr);
    return 0;
}
// 2 4 3 8 10 3 4 0