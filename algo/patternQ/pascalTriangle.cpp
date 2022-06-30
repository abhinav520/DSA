#include <iostream>
using namespace std;
int fact = 1;
int factorial(int num)
{
    if (num == 0 || num == 1)
    {
        return fact;
    }
    else
    {
        fact *= num;
        return factorial(num - 1);
    }
}
int main()
{
    int n;
    cout << "enter length of a PascalTriangle (column len): ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        // for (int j = 0; j < n - i; j++)
        // {
        //     cout << " ";
        // }
        // for(int j=1;j<=(2*i-1);j++){
        //     if(j%2){
        //         cout<<" ";
        //     }
        //     else{
        //         cout<<(factorial(i-1)/(factorial(j-1)*factorial(i-j)));
        //     }
        // }
        for (int j = 0; j <= i; j++)
        {
            cout << factorial(i) / (factorial(j) * factorial(i - j));
        }
        cout << endl;
    }
    return 0;
}