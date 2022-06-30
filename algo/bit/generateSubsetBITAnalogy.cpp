#include <iostream>
using namespace std;

void subset(int* arr,int n){
	for(int i=0;i<(1<<n)/*2^n*/;i++){
		for(int j=0;j<n;j++){
			if(i & (1<<j)){
				cout<<arr[j]<<" ";
			}
		}
		cout<<endl;
	}
}

int main(){
	int n=3;
	int arr[n]={2,0,1};
	subset(arr,n);
	
}
