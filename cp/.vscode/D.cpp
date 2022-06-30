#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            mp[arr[i]-i]++;
        }
        ll ans=0;
        for(auto val:mp){
            ll k=val.second;
            if(k >1){
                ans+=k*(k-1)/2;
            }
        }
        cout<<ans<<endl;

        //-->Below gives TLE (not optimised)
        // int ct=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(arr[j]-arr[i]==j-i){
        //             ct++;
        //         }
        //     }
        // }
        // cout<<ct<<endl;
    }
    return 0;
}