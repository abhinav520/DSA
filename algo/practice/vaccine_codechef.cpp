#include <iostream>
using namespace std;
int grup(int n, int D)
{
    int count = (n % D == 0) ? (n / D) : ((n / D) + 1);
    return count;
}
int main()
{
    int tc;
    cin >> tc;
    int c = tc;

    unsigned int arr[tc];
    while (tc > 0)
    {
        unsigned long N, D;
        cin >> N >> D;
        int A[N];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        int r = 0, nr = 0;
        for (int i = 0; i < N; i++)
        {
            if (A[i] >= 80 || A[i] <= 9)
            {
                r++;
            }
            else
            {
                nr++;
            }
        }
        arr[tc - 1] = (grup(r, D) + grup(nr, D));
        tc--;
    }

    while(c>0)
    {
        cout << arr[c-1] << endl;
        c--;
    }
    return 0;
}