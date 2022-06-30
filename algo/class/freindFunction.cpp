#include <iostream>
using namespace std;
class Complex;    //forward declaration
class Calculator{
public:
    int sumCompComplex(Complex o1,Complex o2);
    int sumRealComplex(Complex o1,Complex o2);
};
class Complex
{
    int a, b;
    // Individually declaring functions as friends
    // friend int Calculator ::sumRealComplex(Complex, Complex);
    // friend int Calculator ::sumCompComplex(Complex, Complex);

    // //Declaring whole class as friend
    friend class Calculator;

public:
    void setNumber(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    void printNumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};



int Calculator ::sumRealComplex(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}

int Calculator ::sumCompComplex(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}

int main()
{
    Complex o1,o2,sum;
    o1.setNumber(4,5);
    o1.printNumber();

    o2.setNumber(1,3);
    o2.printNumber();

    Calculator calc;
    sum.setNumber(calc.sumRealComplex(o1,o2),calc.sumCompComplex(o1,o2));
    sum.printNumber();
    return 0;
}