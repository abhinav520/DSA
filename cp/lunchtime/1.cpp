#include <bits/stdc++.h>
using namespace std;

#define rep(i,begin,end) for(__typeof(end) i=(begin)-((begin)>(end)); i!=(end)-((begin)>(end)); i+=1-2*((begin)>(end)))
#define deb(x) 					 cout << #x << "=" << x << endl  //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) 			 cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec,s,n)  for(int i=s;i<s+n;i++){ cout<<vec[i]<<" ";} cout<<endl
#define input(vec,s,n) 	 vector<int> vec(s+n);for(int i=s;i<s+n;i++){cin>>vec[i];}
#define ini(_n) 				 int _n;cin>>_n;
#define inl(_n) 				 ll _n;cin>>_n;
#define go 							 int tc;cin>>tc;while(tc--)
#define fastio 					 ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;
#define endl "\n"
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return b.first < a.first;
}

void solve(){
    ini(n);
    ini(k);
    string s;
    cin >> s;
    bool unique=true;
    char f = s[0];
    for (auto &c : s)
    {
        if (c != f)
        {
            unique=false;
            break;
        }
    }
    if(unique){
        cout<<n<<"\n";
    }
    multiset<int,greater<int>> arr[26];
    vector<int> v(26);
    for(int i=0;i<26;i++){
        int prefix=0,suffix=0,mid=0;
        v[i]=-1;
        int l=0;
        if (s[l] - 'A' == i){
            while (s[l] - 'A' == i){
                l++;
            }
            prefix++;
        }
        int r=n-1;
        if (s[r] - 'A' == i){
            while (s[l] - 'A' == i){
                r--;
            }
            suffix++;
        }
        k--;
        v[i]=prefix+suffix;
        if(k>0){
            multiset<int,greater<int>> st;
            while(l<=r){
                while(s[l] - 'A' != i && l<=r) l++;
                int cnt=0;
                while(s[l++] - 'A' == i && l<=r) cnt++;
                st.insert(cnt);
            }
            while(k--){
                mid += *(st.begin());
                st.erase(st.begin());
            }
            st.clear();
            v[i]+=mid;
        }

    }
    sort(v.begin(),v.end(),greater<int>());
    cout<<v[0]<<"\n";
}


int main()
{
    // fastio;
    go{
        solve();
    }
    return 0;
}