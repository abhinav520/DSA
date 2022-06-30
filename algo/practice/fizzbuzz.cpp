//This problem is asked in interviews to check your coding skills
//Print num 1-100 with condition that num divisible by 3 -- print fizz
//                                        divisible by 5 -- print buzz 
//                                       divisible by 15 -- print fizzbuzz
#include <iostream>
using namespace std;
int main()
{
    //-->Best coder
    int c3=0, c5=0;
    for (int i = 1; i <= 100; i++)
    {
        c3++;
        c5++;
        string s="";
        if (c3==3){c3=0; s+="fizz";}
        if (c5==5){c5=0; s+="buzz";}
        if(s==""){cout<<i<<endl;}
        else cout<<s<<endl;
    }

    //-->Good coder
    // for (int i = 1; i <= 100; i++)
    // {
    //     string s="";
    //     if (i % 3 == 0){s+="fizz";}
    //     if (i % 5 == 0){s+="buzz";}
    //     if(s==""){cout<<i<<endl;}
    //     else cout<<s<<endl;
    // }

    //-->Bad Coder
    // for(int i=1;i<=100;i++){
    //     if(i%15==0){
    //         cout<<"fizzbuzz"<<endl;
    //     }
    //     else {
    //         if(i%3==0){
    //             cout<<"fizz"<<endl;
    //         }
    //         else if(i%5==0){
    //             cout<<"buzz"<<endl;
    //         }
    //         else{
    //             cout<<i<<endl;
    //         }
    //     }
    // }
return 0;
}