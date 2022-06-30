#include <bits/stdc++.h>
using namespace std;
void solve(int n,int i){
    int t = (n / 2) - i + 1;
    while (t--)
    {
        cout << "  ";
    }
    t = (2 * i - 1);
    while (t--)
    {
        cout << "* ";
    }
    t = (n / 2) - i + 1;
    while (t--)
    {
        cout << "  ";
    }
    cout << endl;
}

int main()
{
    int n;cin>>n;
    if(n==0) exit(1);
    for(int i=1;i<=(n/2)+1;i++){
        solve(n,i);
    }
    for(int i=n/2;i>=1;i--){
        solve(n,i);        
    }
    return 0;
}