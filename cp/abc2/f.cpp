
#include <bits/stdc++.h>
using namespace std;
int arr[1000][1000];
class Solution{
    public:
    int countMin(string s,int l, int r){
        int count=0;
        if(l==0 && r==s.size()) memset(arr,0,sizeof(arr));
        if(l>=r) return 0;
        if(s[l]==s[r]){
            if(arr[l][r]==0) arr[l][r]=countMin(s,l+1,r-1);
            count+=arr[l][r];
        }
        else{
            if(arr[l+1][r]==0) arr[l+1][r]=countMin(s,l+1,r);
            if(arr[l][r-1]==0) arr[l][r-1]=countMin(s,l,r-1);
            count+=min(arr[l+1][r],arr[l][r-1])+1;
        } 
        return count;
    }
    int countMinDp(string s){
        int n=s.size();
        int arr[n][n];
        memset(arr,0,sizeof(arr));
        for()
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        memset(arr,0,sizeof(arr));
        string str;
        cin >> str;
        Solution ob;
        int n=str.size();
        cout << ob.countMin(str,0,n-1) << endl;
    }
return 0;
}