// merge sort is a divide and conquer algo. It divides the array (not actually but thru pen pointer) into two halves, call itself for two halves and then merges the two sorted halves

#include <iostream>
using namespace std;

//Time complexity= O(nlog(n))

void merge(int* arr, int l, int mid, int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int arr1[n1], arr2[n2];
    for(int i=0;i<n1;i++){
        arr1[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        arr2[i]=arr[mid+1+i];
    }
    int i=0;int j=0; int k=l;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr[k++]=arr1[i++];
        }
        else{
            arr[k++]=arr2[j++];
        }
    }
    while(i<n1){
        arr[k++]=arr1[i++];
    }
    while(j<n2){
        arr[k++]=arr2[j++];
    }
}

void mergeSort(int* arr, int l, int r){
    if(l<r){
        int mid=(l+r)/2;        //here l and r are like pen pointer 
        mergeSort(arr,l,mid);   //by pointing at different values size of array is changed relatively
        mergeSort(arr,mid+1,r);  //but actual array is only 1 
        merge(arr,l,mid,r);
    }
}

int main()
{
    
    int arr[]={2,5,4,9,1,6,3};
    mergeSort(arr,0,6);;
    for(int i=0;i<7;i++){
        cout<<*(arr+i)<<" ";
    } 
    return 0;
}