#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter length of a butterfly: ";
    cin>>n;
    
    for(int i=1;i<=n;i++){     //my attempt//     
        int star=0;
        int place=(i+1);
        for(int j=1;j<=(2*n);j++){
            if(star<i){
                cout<<"* "; 
                star+=1;
            }
            else if(place<=(2*n)-i){
                cout<<"  ";
                place+=1;
            }
            else{
                cout<<"* ";
            }
        }
         cout<<endl;
    }
       
    for(int i=n;i>=1;i--){       
        int star=0;
        int place=(i+1);
        for(int j=1;j<=(2*n);j++){
            if(star<i){
                cout<<"* ";
                star+=1;
            }
            else if(place<=(2*n)-i){
                cout<<"  ";
                place+=1;
            }
            else{
                cout<<"* ";
            }
        }
        cout<<endl;        
        
    }



    // for(int i=1;i<=n;i++){            //Aliter//
    //     for(int j=1;j<=i;j++){
    //         cout<<"* ";
    //     }
    //     int space= 2*(n-i);
    //     for(int j=1;j<=space;j++){
    //         cout<<"  ";
    //     }
    //     for(int j=1;j<=i;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }
  
    // for(int i=n;i>=1;i--){
    //     for(int j=1;j<=i;j++){
    //         cout<<"* ";
    //     }
    //     int space= 2*(n-i);
    //     for(int j=1;j<=space;j++){
    //         cout<<"  ";
    //     }
    //     for(int j=1;j<=i;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}