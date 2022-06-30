#include <iostream>
using namespace std;
int firstocc(int* arr,int n, int i, int key){
    if(i==n){       //base case
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return firstocc(arr,n,i+1,key);
}
int lastocc(int *arr, int n, int i, int key){
    if(i==n){       //base case
        return -1;
    }
    int prev= lastocc(arr,n,i+1,key);       //1st recursion then instruction
    if(prev!=-1){
        return prev;
    }
    if(arr[i]=key){
        return i;
    }
    return -1;
}
int main(){
    // int key;
    // cin>>key;
    int arr[]={1,5,2,3,7,2,5,3};
    cout<<(firstocc(arr,8,0,5))<<endl;
    cout<<lastocc(arr,8,0,5);
    return 0;
}