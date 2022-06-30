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
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tc;
  cin >> tc;
  int t = tc;
  while (tc--)
  {
    int a, b, c;
    cin >> a >> b;
    // int arr[3];
    // extendgcd(a, b, arr);
    // int g = arr[2];
    int g = __gcd(a,b);
    cerr<<g<<endl;
    if ((g) >1)
    {
      cout <<"-1\n";
    }
    else
    {
      cout<<(1LL*a*b-a-b+1)<<endl;
    }
  }

  return 0;
}
