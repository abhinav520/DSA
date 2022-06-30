#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int **arr = new int *[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[n];
        }
        if (n == 2)
        {
            cout << -1 << endl;
        }
        else
        {
            int ct = 1;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (ct > n * n)
                    {
                        ct = 2;
                    }
                    arr[i][j] = ct;
                    cout<<arr[i][j]<<" ";
                    ct += 2;
                }
                cout<<endl;
            }
            
        }
    }
    return 0;
}