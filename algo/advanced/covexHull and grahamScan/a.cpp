#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int, set<string>> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        int marks;
        cin >> s >> marks;
        m[marks].insert(s);
    }
    
    for(auto cur_it = m.rbegin();cur_it!=m.rend();cur_it++)
    {
        for (auto i : (*cur_it).second)
        {
            cout << i << " " << cur_it->first << endl;
        }
    }
    return 0;
}


/*3
Eve 78 
Bob 99
Alice 78*/

/*Bob 99  
Alice 78
Eve 78*/