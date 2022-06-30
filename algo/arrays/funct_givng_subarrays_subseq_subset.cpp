//function that gives all possible subarrays, subsequence and subsets
#include <iostream>
using namespace std;
void printArray(int arr[],int start,int end){
    cout<<"[";
    for(int i=start;i<=end;i++){
        cout<<arr[i]<<", ";
    }
    cout<<"\b\b] ";
}
void subarray(int n,int arr[]){
    cout<<"The subarrays of given array are below:\n";
    for(int i=0;i<n;i++){ 
        for(int j=i;j<n;j++){
           printArray(arr,i,j);
        }
        cout<<endl;
    }
}
void subsequence(int n,int arr[],int ci,int arrsubseq[],int cssi){ //ci=current index
    //cout<<"The subsequence of given array are below:\n";   //cssi=current subseq ind
    if(ci>=n){
        printArray(arrsubseq,0,cssi);
        return;
    }
    subsequence(n,arr,++ci,arrsubseq,cssi);    //for excluding element in subsequence 
    arrsubseq[cssi]=arr[ci];
    subsequence(n,arr,++ci,arrsubseq,++cssi);  //for including element in subsequence

}
void subset(int n,int arr[]){
    cout<<"The subset of given attay are below: \n";

}

int main(){
    int n;
    cout<<"Enter size of an array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter value at index "<<i<<" : ";
        cin>>arr[i];
    }
    int arrsubseq[n];
    subarray(n,arr);
    subsequence(n,arr,0,arrsubseq,0);

    return 0;
}