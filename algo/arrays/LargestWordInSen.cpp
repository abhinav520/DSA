#include <iostream>
using namespace std;
int main()
{
    cout << "Enter length of sentence:";
    int n;
    cin >> n;
    char str[n + 1];
    cin.ignore();
    cin.get(str, n,'\n'); //cin is object while getline is a function, to input a complete sentence we use getline
    cout.write(str, n,);
    cout << endl;
    int currlen = 0, maxlen = 0;
    int st = 0, mxst = 0;
    int i = 0;
    while (1)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            if (currlen > maxlen)
            {
                maxlen = currlen;
                mxst = st;
            }
            currlen = 0;
            st = i + 1;
        }
        else
        {
            currlen++;
        }
        if (str[i] == '\0')
        {
            break;
        }
        i++;
    }
    cout << maxlen << endl;
    for (int j = 0; j < maxlen; j++)
    {
        cout << str[mxst + j];
    }
    return 0;
}