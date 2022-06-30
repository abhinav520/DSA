//In any backtracking problems, the algorithm tries to find a path to the feasible solution which has some intermediary checkpoints. In case they don’t lead to a feasible solution, the problem can backtrack from the checkpoints and take another path in search of the solution.

//A Maze is given as N*M binary matrix of blocks where source block is the upper left most block i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][M-1]. A rat starts from source and has to reach the destination. The rat can move only in two directions: forward and down.
//In the maze matrix, 0 means the block is a dead end and 1 means the block can be used in the path from source to destination
//Find the path in terms of 0-1

#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n, int m)
{
    if (x < n && y < n && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}
bool ratInMaze(int **arr, int x, int y, int n, int m, int **solArr)
{
    if (x == (n - 1) && y == (m - 1))        //base case
    {
        solArr[x][y] = 1;
        return true;
    }
    if (isSafe(arr, x, y, n, m))
    {
        solArr[x][y] = 1;
        if (ratInMaze(arr, x + 1, y, n, m, solArr))
        {
            return true;
        }
        if (ratInMaze(arr, x, y + 1, n, m, solArr))
        {
            return true;
        }
        else
        {
            solArr[x][y] = 0;                //bactrack;
            return false;
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout<<"\npossible path :\n";
    int **solArr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solArr[i] = new int[m];
        for (int j = 0; j < n; j++)
        {
            solArr[i][j] = 0;
        }
    }

    if (ratInMaze(arr, 0, 0, n, m, solArr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
/*
9 8
1 0 1 0 1 0 1 0
1 0 1 0 1 0 1 0
1 1 1 0 0 0 0 0
0 1 0 1 1 1 1 1
0 1 1 1 0 0 1 1
0 1 0 1 1 0 1 0
0 1 0 1 0 0 0 0
0 0 0 1 0 0 0 0
0 1 1 1 1 1 1 1 
*/