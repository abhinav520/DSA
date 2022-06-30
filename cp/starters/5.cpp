#include <bits/stdc++.h>
using namespace std;

#define deb(x) 		cout << #x << "=" << x << endl
#define deb2(x, y) 	cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef long long int ll;


int main()
{
    int tc=1;
    cin>>tc;

    while(tc--){
        int n;
        cin>>n;
        vector<int> vec(n),arr(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        double a=(double)vec[0]/arr[0];
        double b=(double)vec[1]/arr[0];
        double ans=(a*a +b*b)/2 + (double)(2*a*b);
        cout<<ans<<endl;
    }

    return 0;
}