/*Q2. Write a program to find 2 unique numbers in an array where all numbers
except two, are present twice.*/
#include <iostream>
using namespace std;
void unique(int *arr, int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
    {
        xorsum ^= arr[i];
    }
    int tempxor = xorsum;
    int newxor = 0;
    int setbit = 0, pos = -1;
    do
    {
        setbit = xorsum & 1;
        pos++;
        xorsum >>= 1;
    } while (setbit != 1);

    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & (1 << pos)) != 0)
        {
            newxor ^= arr[i];
        }
    }
    cout << newxor << ", " << (tempxor ^ newxor);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 6, 2, 1, 3}; //4,6 are unique
    unique(arr, 8);
    return 0;
}