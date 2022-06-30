#include <iostream>
using namespace std;
template <class T>
class Arithmatic
{
private:
    T a;
    T b;
public:
    Arithmatic(T a,T b);
    T Add();
    T Sub();
    T Multiply();
    T Divide();
};
template <class T>
Arithmatic<T>::Arithmatic(T a,T b){
    this->a=a;
    this->b=b;
}
template <class T>
T Arithmatic<T>::Add(){
    T c=a+b;
    return c;
}
template <class T>
T Arithmatic<T>::Sub(){
    return a-b;
}
template <class T>
T Arithmatic<T>::Multiply(){
    return a*b;
}
template <class T>
T Arithmatic<T>::Divide(){
    if(b==0){
        return -1;
    }
    else{
        return a/b;
    }
}

int main()
{
    Arithmatic<float> ar(10,5.2);
    cout<<"Add-"<<ar.Add()<<endl;
    cout<<"Sub-"<<ar.Sub()<<endl;
    cout<<"Multipication-"<<ar.Multiply()<<endl;
    cout<<"Division-";
    if(ar.Divide()==-1){
        cout<<"Denominator can't be 0.";
    }
    else cout<<ar.Divide()<<endl;
    return 0;
}