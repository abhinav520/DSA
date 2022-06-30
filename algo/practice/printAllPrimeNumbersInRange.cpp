#include <iostream>
using namespace std;
int main(){
    cout<<"enter starting value of range : ";
    int start;
    cin>>start;
    cout<<"enter ending value of range : ";
    int end;
    cin>>end;
    cout<<"[";
    for(int i=start;i<=end;i++){
        int j;
        int flag=0;
        for(j=2;j*j<=i;j++){
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(flag==0 && i!=1 && i>0){
            cout<<i<<",";
        }
        
    }
    cout<<"\b]";
    return 0;
}