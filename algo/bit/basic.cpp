#include <iostream>
using namespace std;

int getBit(int n, int pos){
    return ((n & (1<<pos))!=0);   //left shift means multiplying by 2
}//1 is present only at position where we want to find the bit
 //(1<<pos) is the key
int setBit(int n, int pos){  //set bit means we have to apply 1 to that pos  
    return (n | (1<<pos));                                //whereas unset bit is opp
}
int clearBit(int n, int pos){
    int mask= ~(1<<pos);
    return (n & mask);
}

int toogleBit(int n, int pos){  //if bit at req pos is set then it will unset and vice versa
    return (n xor (1<<pos));
}

int updateBit(int n, int pos, int value){
    int mask= ~(1<<pos);  //first do clear bit and then set bit
    n = n & mask;
    return (n & (value << pos));
}

int main()
{
    int n, pos;
    cin >> n >> pos;
    cout<<"getBit : "<<getBit(n, pos)<<endl;
    cout<<"setBit : "<<setBit(n,pos)<<endl;
    cout<<"clearBit : "<<clearBit(n,pos)<<endl;
    cout<<"toogleBit : "<<toogleBit(n,pos)<<endl;
    cout<<"Enter value to be updated:";
    int value;
    cin>>value;
    cout<<"updateBit : "<<updateBit(n,pos,value=1)<<endl;

    return 0;
}