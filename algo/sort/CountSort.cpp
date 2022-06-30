#include <iostream>
using namespace std;

template <class T>
void Print(T& vec, int n, string s){
    cout << s << ": [" << flush;
    for (int i=0; i<n; i++){
        cout << vec[i] << flush;
        if (i < n-1){
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

void CountSort(int A[],int n){
    int mx=A[0];
    for(int i=1;i<n;i++){
        if(mx<A[i]){
            mx=A[i];
        }
    }
    int* count=new int[mx+1];
    for(int i=0;i<=mx;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[A[i]]+=1;
    }
    for(int i=1;i<=mx;i++){
        count[i]+=count[i-1];
    }
    int* output=new int[n];
    for(int i=n-1;i>=0;i--){
        output[--count[A[i]]]=A[i];
    }
    for(int i=0;i<n;i++){
        A[i]=output[i];
    }
    delete []count;
    delete []output;
} 

int main()
{
    int A[] = {2, 5, 8, 12, 3, 6, 7, 10};
    int n = sizeof(A)/sizeof(A[0]);
 
    Print(A, n, "\t\A");
    CountSort(A, n);
    Print(A, n, " Sorted A");
    return 0;
}