#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a length: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        int sum=1;
        for(int j=1;j<=2*i-1;j++){
            if(j%2!=0){
                cout<<sum;
                sum+=1;
            }
            else{
                cout<<" ";
            }
            
        }
        cout<<endl;
    }
    return 0;
}