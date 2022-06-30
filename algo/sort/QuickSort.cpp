#include <iostream>
#include <climits>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

//Quick Sort using INT_Max or infinity
int paritionA(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low;
    int j = high;
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot); // Increment i as long as elements are smaller/equal to pivot
        do
        {
            j--;
        } while (A[j] > pivot); // Decrement j as long as elements are larger than pivot

        if (i < j)
        {
            swap(&A[i], &A[j]);
        }
    } while (i < j);
    swap(&A[low], &A[j]);
    return j;
}

void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int j = paritionA(A, low, high);
        QuickSort(A, low, j);
        QuickSort(A, j + 1, high);
    }
}
int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, 32767};
    int n = sizeof(A)/sizeof(A[0]);

    for(int i=0;i<n-1;i++){
        cout<<A[i]<<" ";
    }  

    QuickSort(A, 0, n-1);
    cout << endl;
    for(int i=0;i<n-1;i++){
        cout<<A[i]<<" ";
    } 
    return 0;
}