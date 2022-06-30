#include <bits/stdc++.h>

using namespace std;

//--------------------debugTemplate-------------------------//
bool debug;
template <typename T, typename U> istream& operator>>(istream &is, pair<T, U> &p) { return is >> p.first >> p.second; }
template <typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p) { return debug ? os << "(" << p.first << ", " << p.second << ")" : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream &operator>>(istream &is, T_container &v) { for (T &x : v) is >> x; return is; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream &operator<<(ostream &os, const T_container &v) { bool f = false; if(debug) { os << "["; for (const T &x : v) { if (f) os << ", "; os << x; f = true; } os << "]"; } else { for (const T &x : v) { if (f) os << " "; os << x; f = true; } } return os; }
void scan() {} template <typename Head, typename ...Tail> void scan(Head &H, Tail &...T) { cin >> H; scan(T...); }
void print() { cout << "\n"; } template <typename Head> void print(const Head &H) { cout << H << "\n"; } template <typename Head, typename ...Tail> void print(const Head &H, const Tail &...T) { cout << H << " "; print(T...); }
template <typename Head> void dbg_out(string var, const Head &H) { cerr << var << " = " << H << endl; }
template <typename Head, typename ...Tail> void dbg_out(string var, const Head &H, const Tail &...T) { for (int i = 0, b = 0; i < int(var.size()); i++) { if (var[i] == '(' || var[i] == '{') { b++; } else if (var[i] == ')' || var[i] == '}') { b--; } else if (var[i] == ',' && b == 0) { cerr << var.substr(0, i) << " = " << H << " | "; dbg_out(var.substr(var.find_first_not_of(' ', i + 1)), T...); break; } } }
template <typename T, typename T1, typename... Tail> T amin(T& a, T1 b, Tail... c) { if(b < a) a = b; if constexpr (sizeof...(c) != 0) { amin(a, c...); } return a; } template <typename T, typename T1, typename... Tail> T amax(T& a, T1 b, Tail... c) { if(b > a) a = b; if constexpr (sizeof...(c) != 0) { amax(a, c...); } return a; }

#ifndef ONLINE_JUDGE
#define dbg(...) debug = true, dbg_out(#__VA_ARGS__, __VA_ARGS__), debug = false
#else
#define dbg(...)
#endif
//--------------------debugTemplate-------------------------//

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER_ARRAY queries
 */
struct maxqueue
{
  stack<pair<int, int>> s1, s2;
  void push(int new_element)
  {
    int maximum = s1.empty() ? new_element : max(new_element, s1.top().second);
    s1.push({new_element, maximum});
  }

  void pop()
  {
    if (s2.empty())
    {
      while (!s1.empty())
      {
        int element = s1.top().first;
        s1.pop();
        int maximum = s2.empty() ? element : max(element, s2.top().second);
        s2.push({element, maximum});
      }
    }
    int remove_element = s2.top().first;
    s2.pop();
  }

  int getMax()
  {
    int maximum;
    if (s1.empty() || s2.empty())
      maximum = s1.empty() ? s2.top().second : s1.top().second;
    else
      maximum = max(s1.top().second, s2.top().second);
    return maximum;
  }
};

vector<int> solve(vector<int> arr, vector<int> queries)
{
  vector<int> ans;
  int n = arr.size();
  for (auto q : queries)
  {
    int mn = INT_MAX;
    maxqueue maxq;
    int i = 0;
    dbg(q);
    for (; i < q; i++)
    {
      maxq.push(arr[i]);
    }
    mn = min(mn, maxq.getMax());
    dbg(mn,maxq.getMax());
    maxq.pop();
    for (; i < n; i++)
    {
      maxq.push(arr[i]);
      mn = min(mn, maxq.getMax());
    dbg(mn,maxq.getMax());
      maxq.pop();
    }
    ans.push_back(mn);
    dbg(ans);
  }
  return ans;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int n = stoi(first_multiple_input[0]);

  int q = stoi(first_multiple_input[1]);

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split(rtrim(arr_temp_temp));

  vector<int> arr(n);

  for (int i = 0; i < n; i++)
  {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  vector<int> queries(q);

  for (int i = 0; i < q; i++)
  {
    string queries_item_temp;
    getline(cin, queries_item_temp);

    int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

    queries[i] = queries_item;
  }

  vector<int> result = solve(arr, queries);

  for (size_t i = 0; i < result.size(); i++)
  {
    fout << result[i];

    if (i != result.size() - 1)
    {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();

  return 0;
}

string ltrim(const string &str)
{
  string s(str);

  s.erase(
      s.begin(),
      find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string &str)
{
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end());

  return s;
}

vector<string> split(const string &str)
{
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos)
  {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
