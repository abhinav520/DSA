#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int bit[N];
void update(int i, int x){
  for(;i<N;i+=(i&(-1))){
    bit[i]+=x;
  }
}
int sum(int i){
  int ans=0;
  for(;i>=1;i-=(i&(-1))){
    ans+=bit[i];
  }
  return ans;
}

int main()
{
  
  return 0;
}