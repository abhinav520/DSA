//LINEAR SEARCH
#include <iostream>
using namespace std;
int linearsearch(int n, int arr[], int key)
{
    for (int i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            return i;
        }
        
    }
    return -1;
}
int main()
{
    int n;
    cout << "Enter size of an array : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value at " << i << " index :";
        cin >> arr[i];
    }
    int key;
    cout << "Enter the value to search : ";
    cin >> key;
    int index = linearsearch(n, arr, key);
    cout<< "The val found at index " << index;
    return 0;
}