#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x) 			 cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) 		 cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec,n) 	 for(int i=0;i<n;i++){ cout<<vec[i]<<" ";} cout<<endl
#define input(vec,n) 	 for(int i=0;i<n;i++){cin>>vec[i];}
#define go 				 int t;cin>>t;while(t--)
#define fastio 			 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    set<int> s1;
    for (int j = 0; j < n; j++)
    {
        cin >> arr[j];
        if (arr[j] > 0)
        {
            s1.insert(j);
        }
    }
    if (s1.size() != 0)
    {
        int temp_arr[n];
        int ans = 0, tmp_max = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == 0)
            {
                auto it = s1.lower_bound(j);
                if (it == s1.begin() || it == s1.end())
                {
                    int x = *s1.begin();
                    int y = *s1.rbegin();

                    x = min(abs(x - j), min(n - j + x, n - x + j));

                    y = min(abs(y - j), min(n - j + y, n - y + j));
                    temp_arr[j] = min(x, y);
                }
                else
                {
                    int x = *it;
                    it--;
                    int y = *it;
                    temp_arr[j] = min(abs(j - x), abs(j - y));
                }
            }
            else
            {
                temp_arr[j] = 0;
            }
            tmp_max = min(k, max(tmp_max, temp_arr[j]));
        }
        int z = k - tmp_max;
        ans += (z * 2 * n);
        for (int j = 0; j < n; j++)
        {

            if (j == 0)
            {
                if (temp_arr[j + 1] < tmp_max)
                    ans += abs(tmp_max - temp_arr[j + 1]);
                if (temp_arr[n - 1] < tmp_max)
                    ans += abs(tmp_max - temp_arr[n - 1]);
            }
            else if (j == n - 1)
            {
                if (temp_arr[0] < tmp_max)
                    ans += abs(tmp_max - temp_arr[0]);
                if (temp_arr[j - 1] < tmp_max)
                    ans += abs(tmp_max - temp_arr[j - 1]);
            }
            else
            {
                if (temp_arr[j - 1] < tmp_max)
                    ans += abs(tmp_max - temp_arr[j - 1]);
                if (temp_arr[j + 1] < tmp_max)
                    ans += abs(tmp_max - temp_arr[j + 1]);
            }
            ans += arr[j];
        }
        cout << ans << "\n";
    }
    else
    {
        cout << "0\n";
    }
}

int main()
{
    fastio;
    go
    {
        solve();
    }

    return 0;
}