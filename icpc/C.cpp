#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  int k=t;
  while (t--)
  {
   int g,p; cin>>g>>p;
   int i=g;
   cout << "Team #" << (k - t) << endl;
   cout << "Games: " << g << endl;
   cout << "Points: " << p << endl;
   cout << "Possible records:" << endl;
   while(i>=0)
   {
     int res=(p-i*3);
     int rem=g-i;
     if(rem>=res&&rem>=0&&res>=0){
       
     cout<<i<<"-"<<(res)<<"-"<<(rem-res)<<endl;;
     }
     i--;
   }
  }
  return 0;
}