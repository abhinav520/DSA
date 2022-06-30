#include <iostream>
#include <deque>
#include <vector>
#include <set>
using namespace std;

void O_1_SlidWin(vector<int> arr, vector<int> ans, deque<int> dq,int n, int k){
    int i;
    for (i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[dq.back()] < arr[i])
        { //want dq in decreasing oder
            dq.pop_back();
        }
        dq.push_back(i); // only inputing index
    }
    ans.push_back(arr[dq.front()]);
    for (; i < n; ++i)
    {
        if (dq.front() == i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(arr[dq.front()]);
    }

    for (int j : ans)
    {
        cout << j<<" ";
    }
    cout<<endl;
}
void O_nxlogn_SlidWind(vector<int> arr, vector<int> ans, deque<int> dq,int n, int k){
    multiset <int,greater<int>> s;
    for(int i=0;i<k;i++){
        s.insert(arr[i]);
    }
    ans.push_back(*s.begin());
    for(int i=k;i<n;i++){
        s.erase(s.lower_bound(arr[i-k]));
        s.insert(arr[i]);
        ans.push_back(*s.begin());
    }
    for (int j : ans)
    {
        cout << j<<" ";
    }
    cout<<endl;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n), ans;
    deque<int> dq;
    for (auto &i : arr)
    {
        cin >> i;
    }
    O_1_SlidWin(arr,ans,dq,n,k);
    O_nxlogn_SlidWind(arr,ans,dq,n,k);
    return 0;
}