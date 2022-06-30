#include <iostream>
using namespace std;
int main()
{
    int n, m; //n=rows ; m=column;
    // cout << "Enter no. of rows: ";
    cin >> n;
    // cout << "Enter no. of columns: ";
    cin >> m;
    int arr[n][m]; //2D array can int,float,char,bool
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }

    }
    int rst = 0, rnd = n - 1, cst = 0, cnd = m - 1;
    while (cst <= cnd && rst <= rnd)
    {
        //for row start
        for (int i = cst; i <= cnd; i++)             //i=row traversing
        {                                          //j=column traversing
            cout << arr[rst][i] << " ";
        }
        rst++;

        //for column end
        for (int j = rst; j <= rnd; j++)
        {
            cout << arr[j][cnd] << " ";
        }
        cnd--;

        //for row end
        for (int i = cnd; i >= cst; i--)
        {
            cout << arr[rnd][i] << " ";
        }
        rnd--;

        //for column start
        for (int j = rnd; j >= rst; j--)
        {
            cout << arr[j][cst] << " ";
        }
        cst++;
    }
    cout<<"\b\b";

    return 0;
}