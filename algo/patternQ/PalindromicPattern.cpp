#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter length of a palindrome: ";
    cin>>n;
    // for(int i=n;i>=1;i--){
    //     for(int j=1;j<i;j++){
    //         cout<<"  ";
    //     }
    //     for(int j=(n-i+1);j>=1;j--){
    //         cout<<j<<" ";
    //     }
    //     for(int j=2;j<=n-i+1;j++){
    //         cout<<j<<" ";
    //     } 
    //     for(int j=1;j<i;j++){
    //         cout<<"  ";
    //     }
    //     cout<<endl;   
    // }



//aliter//
    for(int i=1;i<=n;i++){
        int space=1;
        int s1=i;
        int s2=2;
        for(int j=1;j<=(n*2-1);j++){
            if(space<=(n-i)){
            cout<<"  ";
            space+=1;
            }
            else if(s1>=1){
                cout<<s1<<" ";
                s1-=1;
            }
            else if(s2<=i){
                cout<<s2<<" ";
                s2+=1;
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
      
    }


    return 0;
}
