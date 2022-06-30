#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  int k=t;
  while (t--)
  {
    int c;
    cin >> c;
    vector<long long> car(c);
    for (auto &i : car)
      cin >> i;
    vector<long long> time(4 * c);
    for(auto &i: time)
            cin >>i;
    sort(car.begin(), car.end());
    sort(time.rbegin(), time.rend());
    long long maxi=-1;
    for (int i = 0; i < c; i++)
    {
     maxi=max(maxi,car[i]+time[i*4]);
    }
    cout<<"Trip #"<<k-t<<": "<<maxi<<endl;
  }
  return 0;
}