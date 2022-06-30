#include <iostream>
using namespace std;
using namespace std;

typedef long long ll;

int main() {
    int tc;
    cin>>tc;
    while(tc--)
    {
        ll c;
        cin>>c;
        int d=(int)(log(c)/log(2))+1;
        int last=pow(2,d);
        cout<<d<<", "<<last;
    }
	return 0;
}
