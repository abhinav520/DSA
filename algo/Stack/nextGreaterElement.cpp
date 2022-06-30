#include <bits/stdc++.h>
using namespace std;


int main() {
    vector<pair<int,int>> m;
    stack<int> stk;
    int n;
    cin>>n;
    int arr[n];
    vector<int> nge(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        while(!stk.empty() && arr[stk.top()]<arr[i]){
            nge[stk.top()]=i;
            stk.pop();
        }
        stk.push(i);
    }
    while(!stk.empty()){
        nge[stk.top()]=-1;
        stk.pop();
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  "<<((nge[i]==-1)? -1 : arr[nge[i]])<<endl;
    }
    return 0;
}
