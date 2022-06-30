#include <iostream>
#include <string>
using namespace std;
int add(int a, int b)
{
    int c = a + b;
    return c;
}

class Employee
{
private:
     int secretPassword; 

public:
    string name;
    int salary;

    Employee(string n,int s,int sp)
    {
        this->name= n;
        this->salary=s;
        this->secretPassword=sp;

    }
    void printDetails()
    {
        cout << "The name of the employee is " << this->name << " and Salary of the employee is " << this->salary << " dollars"<<endl; 
    }
    void getsecretPassword()
     {
         cout<<"The secret password is "<<this->secretPassword<<endl;
     }

} ;
//inheritence//    //all the properties of base class is there in child class, in child class we can edit, add or even overwrite the base class//
class Programmer : public Employee
{
public:
    int errors;
};




int main()
{
    //  cout<< "hello world"<<endl<<"hi abhi"<<endl;
    //  cout<< "and abhi\n";
    /*int a,b,c;
a=1,b=2,c=3;
cout<<a<<endl<<"b\n"<<c;*/

    //camel case notation//
    /*int MarksInMaths= 95;
    cout<<"Marks scored in Maths is "<<MarksInMaths;*/

    /* short a;
    long b;
    long long c;
    int z;
    float const score1=35.325; //const value cant change//
    double score2=34.44568;
    long double score3=25.35648965;
    cout<<"score is\n"<<score1<<endl<<score2<<endl<<score3;*/

    //input|output|operators//

    // int a,b;
    // cout<<"enter first number"<<endl;
    // cin>>a;
    // cout<<"enter second number"<<endl;
    // cin>>b;
    // cout<<"a + b ="<<a+b<<endl;
    // cout<<"a - b ="<<a-b<<endl;
    // cout<<"a * b ="<<a*b<<endl;
    // cout<<"a / b ="<<(float)a/b<<endl; //float is used as typecasting//
    /* Typecasting is used in lower to higher preference order i.e 
bool -> char -> short int -> int -> unsigned int -> long -> unsigned -> 
long long -> float -> double -> long double*/

    // float a= 31.25;
    // int b=static_cast<int>(a);
    // cout<<b;

    //if else//
    // int age; //declration//
    // cout<<"enter age = ";
    // cin>>age;

    // switch(age)
    // {
    // case 12:
    //     cout<<"You are 12 years old"<<endl;
    //     break;
    // case 18:
    //     cout<<"You are 18 years old"<<endl;
    //     break;
    // default:
    //     cout<<"You are neithet 18 nor 12"<<endl;

    // }
    //  switch (expression)   //switch snippet//
    // {
    // case /* constant-expression */:
    //     /* code */
    //     break;

    // default:
    //     break;
    // }

    // if(age>150 || age<1){
    //     cout<<"invalid age";
    // }
    // else if(age>18)
    // {
    //     cout<<"allowed to vote"<<endl;
    // }
    // else{
    //     cout<<"not allowed to vote"<<endl;
    // }

    //loop//
    // int index=0;
    // while(index<34){
    //     cout<<"The value of index is"<<index<<endl;
    //     index=index+1;
    // }

    // do{
    //     cout<<"The value of index is"<<index<<endl;
    //     index=index+1;
    // }while(index<20);
    // for (int i = 0; i < 20; i++)
    // {
    //     cout <<"the value of i is"<<i<<endl;
    // }

    //function//
    // int a,b;
    // cout<<"enter first number"<<endl;
    // cin>>a;
    // cout<<"enter second number"<<endl;
    // cin>>b;
    // cout<<"the sum is "<<add(a,b);

    //array//
    // int arr2d[2][3]={{2,4,9},
                        {1,5,8}};
    // for(int i=0;i<2;i++)
    // {
    //     for(int j=0;j<3;j++)
    //     {
    //         cout<<"the value at"<<i<<","<<j<<"th index is"<<arr2d[i][j]<<endl;
    //     }
    // }
    // int a=45;
    // float c=(float)a/34;
    // cout<<c;
    // string name= "abhinav";
    // cout<<"the name is "<<name<<endl;
    // cout<<"the length of name is "<<name.length()<<endl;
    // cout<<"the name is "<<name.substr(0,5)<<endl;
    //pointer//
    // int a=34;
    // int* ptra;
    // ptra= &a;
    // cout<<"The value of a is "<<a<<endl;
    // cout<<"The value of a is "<<*ptra<<endl;
    // cout<<"The address of a is "<<ptra<<endl;
    // cout<<"The address of a is "<<&a<<endl;

    // Employee abhi;
    // abhi.name = "Abhinav";
    // abhi.salary = 100;
    // abhi.printDetails();

    // cout << "The name of the employee is " << abhi.name << " and Salary of the employee is " << abhi.salary << " dollars";

    // Employee abhi("Abhinav",103,10246);
    // abhi.printDetails();
    // abhi.getsecretPassword();
    cout<<(double)4.0+(double)4.0;
    return 0;
}