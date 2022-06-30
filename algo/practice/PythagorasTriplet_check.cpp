#include <iostream>
#include <algorithm>
using namespace std;
// int max(int n1, int n2)
// {
//     if (n1 > n2)
//     {
//         return n1;
//     }
// }
bool check(int x, int y, int z);

int main()
{
    int x, y, z;
    cout << "Enter three numbers : ";
    cin >> x >> y >> z;
    if (check(x, y, z))
    {
        cout << "Pythogoras Triplet";
    }
    else
    {
        cout << "Not a pythogoras Triplet";
    }
    return 0;
}
bool check(int x, int y, int z)
{
    int a;
    a = max(x, max(y, z));

    // int b,c;
    // if (a == x)
    // {
    //     b = y;
    //     c = z;
    // }
    // else if (a == y)
    // {
    //     b = x;
    //     c = z;
    // }
    // else
    // {
    //     b = x;
    //     c = y;
    // }
    if (a * a == (x*x+y*y+z*z-a*a))
    {
        return true;
    }
    else
    {
        return false;
    }
}