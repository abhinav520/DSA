#include <iostream>
using namespace std;
void toh(int n,char src,char helper,char dest){   //toh--Tower of hanoi
    if(n==0)         //base case
        return; 
    toh(n-1,src,dest,helper);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    toh(n-1,helper,src,dest);
}
int main()
{
    cout<<"Enter num of disc: ";
    int n;
    cin>>n;  //no of disc
    char src='a';
    char helper='b';
    char dest='c';
    toh(n,src,helper,dest);
    return 0;
}