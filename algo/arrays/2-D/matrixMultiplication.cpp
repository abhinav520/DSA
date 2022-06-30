#include <iostream>
using namespace std;
int main()
{
    //Dimension of matrices
    int n, m, o;

    cout << "Enter no. of rows of first matrix: ";
    cin >> n;

    cout << "Enter no. of column of first matrix which is same as no. of rows of second matrix: ";
    cin >> m;

    cout << "Enter no. of column of second matrix: ";
    cin >> o;

    //Enter first matrix(n*m)
    cout << "Enter values of first matrix of order "<<n<<"*"<<m<<"\n";
    int matrix1[n][m];
    for (int i = 0; i < n; i++) //i for rows
    {
        for (int j = 0; j < m; j++) //j for column
        {
            cin >> matrix1[i][j];
        }
    }

    //Enter second matrix(m*o)
    cout << "Enter values of second matrix of order " <<m<<"*"<<o<<"\n";
    int matrix2[m][o];
    for (int j = 0; j < m; j++) //j for rows
    {
        for (int k = 0; k < o; k++) //k for column
        {
            cin >> matrix2[j][k];
        }
    }
    //Ans matrix initialization
    //multiplication of n*m and m*o is order of n*o
    int multi[n][o];
    for (int i = 0; i < n; i++) //j for rows
    {
        for (int k = 0; k < o; k++) //k for column
        {
            multi[i][k]=0;
        }
    }

    //matrix multiplication
    for (int i = 0; i < n; i++) // i for rows of matrix1
    {
        for (int k = 0; k < o; k++) //k for col of matrix2
        {
            for(int j = 0; j < m; j++) //j-both col of(matrix1) and row of (matrix2)
            {
                multi[i][k] += matrix1[i][j] * matrix2[j][k];
            }
        } 
    }


    //printing multiplication matrix
    for (int i = 0; i < n; i++) // i for rows
    {
        for (int k = 0; k < o; k++) //k for column
        {
            cout<<multi[i][k]<<" ";
        }
        cout<<endl;
    }

    return 0;
}