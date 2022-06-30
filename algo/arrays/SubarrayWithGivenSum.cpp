#include <iostream>
using namespace std;
int main()
{
    int n,s;
    cin>>n>>s;
    unsigned int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i=0,j=0,currsum=0;               //two pointer approach
    for(;arr[j]+currsum<s;j++){
        currsum+=arr[j];
        
    }
    if(currsum==s){
        cout<<i+1<<" "<<j+1;  //add 1 becoz 1 based index
        return 0;
    }
    for(;j<n;j++){
        currsum+=arr[j];       
        while(currsum>s){
            currsum-=arr[i];
            i++;
        }
        if(currsum==s){
            cout<<i+1<<" "<<j+1;
            return 0;
        }
    }
    return 0;   
}