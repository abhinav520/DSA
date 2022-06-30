//Search for duplicate strings in an array of strings
//or more precisely
//Given a list of n strings si, each no longer than m characters, find all the duplicate strings and divide them into groups.
//O(nm+nlogn)  time.  (ignoring time of testcases)

#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x) 					 cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) 			 cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec,n) 	 for(int i=0;i<n;i++){ cout<<vec[i]<<" ";} cout<<endl
#define input(vec,n) 		 for(int i=0;i<n;i++){cin>>vec[i];}
#define ini(_n) 				 int _n;cin>>_n;
#define inl(_n) 				 ll _n;cin>>_n;
#define go 							 int tc;cin>>tc;while(tc--)
#define fastio 					 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;

long long compute_hash(string const &s);

vector<vector<int>> group_identical_strings(vector<string> const &s)
{
  int n = s.size();
  vector<pair<long long, int>> hashes(n);
  for (int i = 0; i < n; i++)
    hashes[i] = {compute_hash(s[i]), i};

  sort(hashes.begin(), hashes.end());

  vector<vector<int>> groups;
  for (int i = 0; i < n; i++)
  {
    if (i == 0 || hashes[i].first != hashes[i - 1].first)
      groups.emplace_back();
    groups.back().push_back(hashes[i].second);
  }
  return groups;
}

long long compute_hash(string const &s)
{
  const int p = 31;
  const int m = 1e9 + 9;
  long long hash_value = 0;
  long long p_pow = 1;
  for (char c : s)
  {
    hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
    p_pow = (p_pow * p) % m;
  }
  return hash_value;
}

int main()
{
  fastio;
  go{
    ini(n);
    vector<string> s(n);
    for(auto &str:s){
      cin>>str;
    }
    vector<vector<int>> v = group_identical_strings(s);
    for(auto x:v){
      for(int y:x){
        cout<<y<<" ";
      }
      cout<<endl;
    }
    cout<<endl;
  }
  return 0;
}