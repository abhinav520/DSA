#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x) 					 cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) 			 cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec,s,n)  for(int i=s;i<s+n;i++){ cout<<vec[i]<<" ";} cout<<endl
#define input(vec,s,n) 	 vector<int> vec(s+n);for(int i=s;i<s+n;i++){cin>>vec[i];}
#define ini(_n) 				 int _n;cin>>_n;
#define inl(_n) 				 ll _n;cin>>_n;
#define go 							 int tc;cin>>tc;while(tc--)
#define fastio 					 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;


bool solve(int *g,int*h){
  ini(n);
  ini(s);
  input(a, 1, n);
  int mx=0;
  int i=0,j=1;
  ll balance=s;
  while(j<=n){
    ll bachahua=balance+a[j];
    if(bachahua>=0){
      j++;
      balance=bachahua;
    }
    else{
      i++;
      if(mx<(j-i)){
        (*g)=i;
        (*h)=j-1;
        mx=(j-i);
      }
      if(i==j){
        j++;
        balance=s;
      }
      else{
        balance -= a[i];
      }
    }
  }
  if(j==n+1){
    i++;
    if (mx < (j - i))
    {
      (*g) = i;
      (*h) = j - 1;
      mx = (j - i);
    }
    if (i == j)
    {
      j++;
      balance = s;
    }
    else
    {
      balance -= a[i];
    }
  }
  if(*g==-1 || *h==-1) return false;
  return true;
  
}


int main()
{
  fastio;
  go{
    int g=-1,h=-1;
    if(solve(&g,&h)){
      cout<<g<<" "<<h<<endl;
    }
    else{
      cout<<-1<<endl;
    }
  }
  return 0;
}