// HimanShu09 //
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int int64_t
void read(vector<int> &a);
void read(vector<string> &a);
void read(vector<vector<int>> &a);
void read(vector<pair<int, int>> &a);
#define str(n) to_string(n)
#define binary(n) std::bitset<32>(n).to_string()
#define all(arr) arr.begin(), arr.end()
#define RANDOM mt19937 tourist(chrono::steady_clock::now().time_since_epoch().count())
#define random(x, y) uniform_int_distribution<int>(x, y)(tourist)
#define fastIO1 ios_base::sync_with_stdio(false)
#define fastIO2 cin.tie(NULL)
#define Google(t) cout << "Case #" << t << ": ";

void solve()
{
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  if (k == 1)
  {
    cout << 0 << endl;
    return;
  }

  vector<int> a;
  int prev = -1;
  for (int i : arr)
  {
    if (prev == i)
    {
      continue;
    }
    a.push_back(i);
    prev = i;
  }

  int ugly = 0;
  for (int i = 1; i < a.size(); i++)
  {
    cout<<a[i]<<endl;
    if (a[i] != a[i - 1])
      ugly++;
  }

  vector<int> f(k + 1, 0);

  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << " ";
    if (i == 0)
    {
      f[a[i]]++;
    }
    else if (i == a.size() - 1)
    {
      f[a[i]]++;
    }
    else
    {
      if (a[i - 1] != a[i + 1])
      {
        f[a[i]]++;
      }
      else
      {
        f[a[i]] += 2;
      }
    }
  }

  for (int i = 1; i <= k; i++)
  {
    cout << i << " " << ugly << " " << f[i] << endl;
    cout << ugly - f[i] << " ";
  }
  cout << endl;
}

int32_t main()
{
  // fastIO1;
  // fastIO2;
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; tt++)
  {
    Google(tt);
    solve();
  }

  return 0;
}
void read(vector<int> &a)
{
  for (int i = 0; i < a.size(); i++)
    cin >> a[i];
}
void read(vector<string> &a)
{
  for (int i = 0; i < a.size(); i++)
    cin >> a[i];
}
void read(vector<vector<int>> &a)
{
  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < a[i].size(); j++)
      cin >> a[i][j];
}
void read(vector<pair<int, int>> &a)
{
  for (int i = 0; i < a.size(); i++)
    cin >> a[i].first >> a[i].second;
}
