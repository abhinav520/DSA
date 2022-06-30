#include <iostream>
using namespace std;

// struct rectangle{
//     int len;
//     int bre;

// void initialize(int l,int b){
//     len=l;
//     bre=b;
// }
// int area(){
//     return len*bre;
// }
// int perimeter(){
//     return 2*(len+bre);
// }
// };

//in c++ = structures and class are same execpt in structures everything is public whereas in class everything is private
//in c++ = unlike structures, in class direct initialization cant be done
//         eg rectangle r={10,15}     <-- not allowed in class

class rectangle
{
public:

    int len;
    int bre;

void initialize(int l,int b){
    len=l;
    bre=b;
}
int area(){
    return len*bre;
}
int perimeter(){
    return 2*(len+bre);
}
};
int main()
{
    rectangle r;
    // rectangle r={0,0};                      //for class this is invalid, for structure it is valid
    cout<<"Enter the lenght and breadth: ";
    int l,b;
    cin>>l>>b;
    r.initialize(l,b);
    cout<<"Area: "<<r.area()<<endl;
    cout<<"Perimeter: "<<r.perimeter();
    return 0;
}