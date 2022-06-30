#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef long long ll;


void removalTime(map<int,vector<int>> &to_discharge,set<int> &vaccant_centre,int x){
    if(to_discharge.size()==0) return;
    auto it=to_discharge.upper_bound(x);
    if(it==to_discharge.begin()){
        return;
    }
    for(auto i=to_discharge.begin();i!=it;i++){
		for(auto itr=i->second.begin();itr!=i->second.end();itr++){
            vaccant_centre.insert(*itr);
        }
        to_discharge.erase(i);
    }
}
int find_next_vaccant_centre(set<int> &vaccant_centre,int x){
    if(vaccant_centre.size()==0) return -1;
    auto it=(vaccant_centre.lower_bound(x));
    if(it==vaccant_centre.end()) it=vaccant_centre.begin();
    int vaccant=*it;
    vaccant_centre.erase(it);
    return vaccant;
}
int main()
{
    map<int,vector<int>> to_discharge;
    set<int> vaccant_centre;
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int arr[m] = {0};
    
    vector<pair<int,int>> avl(n); 
    for (int i = 0; i < n; i++)
    {
        cin >> avl[i].x;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> avl[i].y;
    }
    for (int i = 0; i < m; i++)
    {
        vaccant_centre.insert(i);
    }
    sort(avl.begin(),avl.end());

    int go, b;
    // to_discharge.insert({avl[0].x+avl[0].y,{0}});
    // vaccant_centre.erase(0);
    for (int i = 0; i < n; i++)
   {
        go=i%m;
        removalTime(to_discharge,vaccant_centre,avl[i].x);
        //check if any centre is vaccant
        //if(vaccant_centre.size()==0) continue;
        go=find_next_vaccant_centre(vaccant_centre,go);
        if(go!=-1){
            to_discharge[avl[i].x+avl[i].y].push_back(go);
            arr[go]++;
        }
    }

    for(int i=0;i<m;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}