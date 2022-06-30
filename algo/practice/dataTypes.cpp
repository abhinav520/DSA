#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";


    // Declare second integer, double, and String variables.
    string s2;
    int i2;
    double d2;
    // Read and save an integer, double, and String to your variables.
    cout<<"Enter integer : ";
    cin>>i2;
    cout<<endl<<"Enter double : ";
    cin>>d2;
    cout<<endl<<"Enter string : ";
    cin>>s2;
    
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.
    
    // Print the sum of both integer variables on a new line.
    cout<<endl<<"the sum of both integer : "<<(i+i2);
    // Print the sum of the double variables on a new line.
    cout<<endl<<"the sum of both double : "<<fixed<<setprecision(1)<<(d+d2);
    // Concatenate and print the String variables on a new line
    string c= s+s2;
    cout<<endl<<"the concatenated string : "<<c;
    // The 's' variable above should be printed first.

    return 0;
}