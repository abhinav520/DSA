#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int n,m;
    cin>>n>>m;
    multiset<int> tickets;
    vector<int> customer(m);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        tickets.insert(-temp);
    }
    for(int i=0;i<m;i++){
        cin>>customer[i];
    }
    //sort(begin(tickets),end(tickets));
    int i;
    for(i=0;i<n;i++){
        if(i==m) break;
        auto it=tickets.lower_bound(-customer[i]);
        if(it!=tickets.end()){
            cout<<-1*(*it)<<endl;
            tickets.erase(it);
        }
        else{
            cout<<-1<<endl;
        }
        
    }
    for(;i<m;i++){
        cout<<-1<<endl;
    }
    return 0;
}