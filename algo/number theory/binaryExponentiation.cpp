#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m =1e9+7;
const ll M =1e18+7;


int binMultiplyRec(int a, int b){
   int res=binMultiplyRec(a,b/2);
  return (((b&1)?a:1)*1LL*res*res)%m;
}

int binMultiplyIter(int a, int b){
  int ans=1;
  while(b){
    if(b&1){
      ans=(ans*1LL*a)%m;
    }
    a=(a*a)%m;
    b>>=1;
  }
  return ans;
}
////////////////////////////
/*
large exponential
if A , B and M are in the range of 1e18
*/
ll largeMultiply(ll a, ll b);
// TC- (log(n))*(log(n))
ll largeExpo(ll A, ll B){
  ll ans=1;
  while(B){
    if(B&1){
      // ans=(ans*1LL*A)%M          // results in overflow
      ans=largeMultiply(ans,A);
    }
    A=largeMultiply(A,A);
    B>>=1;
  }
  return ans;
}

ll largeMultiply(ll a, ll b){
  ll ans = 0;
  while (b)
  {
    if (b & 1)
    {
      // ans=(ans*1LL*A)%M          // results in overflow
      ans = (ans+a)%M;
    }
    a = (a+a)%M;
    b >>= 1;
  }
  return ans;
}

// if b is large
// a^b mod m = a^(b mod etf(m)) mod m






int main()
{
  int a,b;
  cin>>a>>b;

  return 0;
}