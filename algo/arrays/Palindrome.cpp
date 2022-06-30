#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char arr[n + 1]; //char array always end with null character "\0"
    cin >> arr;   //directly take input no need to use loop
  //cout<<arr; cout<<arr[5]; ,etc   // directly take output
    bool check = 1;
    for (int i = 0; i < n/2; i++)
    {
        if (arr[i] != arr[n - 1 - i])
        {
            check = 0;
        }
    }
    check == 0 ? cout << "Not a Palindrome." : cout << "It is palindrome.";
    return 0;
}