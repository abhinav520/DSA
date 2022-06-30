#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0)
#define all(v) v.begin(), v.end()
#define endl '\n'
#define int int64_t
multiset<int> st;
int target;
bool rec(vector<int> &v, int i, int n, int sum1, int total)
{
  if (sum1 - (total - sum1) == target)
  {
    return true;
  }
  if (i == n)
  {
    return false;
  }
  st.insert(v[i]);
  if(rec(v, i + 1, n, sum1 + v[i], total)){
    return true;
  }
  st.erase(st.find(v[i]));
  if(rec(v, i + 1, n, sum1, total)){
    return true;
  }
  return false;
} 

signed main()
{
  fastio;
  int n;
  cin >> n;
  cin >> target;
  vector<int> v(n);
  for (auto &x : v)
  {
    cin >> x;
  }
  int sum1 = 0;
  int total = accumulate(all(v), 0LL);
  if (rec(v, 0, n, sum1, total))
  {
    vector<int> s2;
    for (auto &x : v)
    {
      if (st.find(x) == st.end())
      {
        s2.push_back(-x);
      }
    }
    while (!st.empty())
    {
      cout << *st.begin() << " ";
      st.erase(st.begin());
    }
    cout << endl;
    for (auto &x : s2)
    {
      cout << x << " ";
    }
    cout << endl;
  }
  else
  {
    "Not possible\n";
  }
  return 0;
}