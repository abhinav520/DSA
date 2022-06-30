#include <iostream>
#include <vector>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// class Max_Heap{
// public:

// }
void Insert(vector<int> &vec, int key)
{
    //Insert key at the end
    int i = vec.size();
    vec.emplace_back(key);
    int temp = key;
    // Rearrange elements: O(log n)
    while (i > 1 && temp > vec[i / 2])
    {
        vec[i] = vec[i / 2];
        i = i / 2;
    }
    vec[i] = key;
}
void CreateHeap(vector<int>& vec, int A[],int n){
    //O(n logn)
    vec[1]=A[0];
    for(int i=2;i<=n;i++){
        Insert(vec,A[i-1]);
    }
}

void insertInplace(int A[], int n)
{
    int i = n;
    int temp = A[n];
    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

void createHeap(int A[], int n){
    for (int i=1; i<=n; i++){
        insertInplace(A, i);
    }
}
 
void Delete(int A[],int n){
    int x=A[1];
    A[1]=A[n-1];
    int i=0;
    int j=2*i;
    while(j<n-1){
        if(A[j] < A[j+1]){
            j+=1;
        }
        if(A[i]<A[j]){
            swap(A[i],A[j]);
        }
        else{
            break;
        }
    }
}

template <class T>
void Print(T& vec, int n, char c){
    cout << c << ": [";
    for (int i=1; i<=n; i++){
        cout << vec[i];
        if (i <= n-1){
            cout << ", ";
        }
    }
    cout << "]" << endl;
}
 

int main()
{
    cout << "Create Heap" << endl;
    int b[] = {-1,10, 20, 30, 25, 5, 40, 35}; //not using 0th valu
    Print(b,( sizeof(b)/sizeof(b[0]))-1, 'b');

    vector<int> v;
    v.emplace_back(-1); //vec[0]--> i'm not using it
    CreateHeap(v, b, (sizeof(b)/sizeof(b[0]))-1);
    Print(v, v.size()-1, 'v');

    cout << "Inplace Insert" << endl;
    createHeap(b, sizeof(b)/sizeof(b[0])-1);
    Print(b, sizeof(b)/sizeof(b[0]), 'b');

    return 0;
}