#include <bits/stdc++.h>
using namespace std;

#define deb(x) 		cout << #x << "=" << x << endl
#define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef long long int ll;


int main()
{
    int n=1;
    cin>>n;
    int tax=1.08*n;
    if(tax<206) cout<<"Yay!\n";
    else if(tax==206) cout<<"so-so\n";
    else cout<<":(\n";

    return 0;
}