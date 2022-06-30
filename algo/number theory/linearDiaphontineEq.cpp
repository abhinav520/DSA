// prerequisite- extended Euclidean theorem
// solution of ax+by=gcd(a,b)
#include <bits/stdc++.h>
using namespace std;

void extendgcd(int a, int b, int *v)
{
  if (b == 0)
  {
    v[0] = 1; // x
    v[1] = 0; // y
    v[2] = a; // gcd
    return;
  }
  extendgcd(b, a % b, v);
  int x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
  return;
} // pass an arry of size 3



int main()
{
  int tc;cin>>tc;
  int t=tc;
  while(tc--){
    int a, b, c;
    cin >> a >> b >> c;
    int arr[3];
    extendgcd(a, b, arr);
    int g = arr[2];
    // int g = __gcd(a,b);
    if (c % g != 0)
    {
      cout <<"Case "<<t-tc<< ": No\n";
    }
    else{
      int x, y;
      x = (c / g) * arr[0];
      y = (c / g) * arr[1];
      cout << "Case " << t-tc<< ": Yes\n";
      cout << x << " " << y << endl;
    }  
  }
  
  return 0;
}