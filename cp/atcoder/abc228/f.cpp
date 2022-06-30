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
vector<string> ans;
char closingBracket = ')';
char openingBracket = '(';

void parenthesisRec(int n, string &str, int oc, int cc)
{
  if (oc == n && cc == n)
  {
    ans.push_back(str);
    // str.pop_back();

    return;
  }
  // if (oc == cc)
  // {
  //   str.push_back(openingBracket);
  //   parenthesisRec(n, str, oc + 1, cc);
  //   str.pop_back();
  //   // oc--;
  // }
  if(oc<n){
    str.push_back(openingBracket);
    parenthesisRec(n, str, oc + 1, cc);
    str.pop_back();
  }
  if (oc>cc)
  {
  // str[str.size() - 1] = '(';
    str.push_back(closingBracket);
    parenthesisRec(n, str, oc, cc + 1);
    str.pop_back();
  }
  // cc--;
  
  // str.pop_back();
  
}
vector<string> generateParenthesis(int n)
{
  string s;
  s.push_back(openingBracket);
  parenthesisRec(n, s, 1, 0);
  return ans;
}

int main()
{
  ini(n);
  vector<string> vec= generateParenthesis(n);
  for(auto &s:vec){
    cout<<s<<" ";
  }
  return 0;
}