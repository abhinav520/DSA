#include <iostream>
using namespace std;
int binarysearch(int n, int arr[], int key)
{
    int beg = 0;
    int last = n-1;
    while (beg<=last)
    {
        int mid = (beg + last) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            beg = mid+1;
        }
        else
        {
            last = mid-1;
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
        int index = binarysearch(n, arr, key);
        cout << "The val found at index " << index;
        return 0;
    }