#include <bits/stdc++.h>
using namespace std;

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define deb(x) cout << #x << "=" << x << endl //'#' sign to get exact name of an argument passed to a macro
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define output(vec, s, n)           \
    for (int i = s; i < s + n; i++) \
    {                               \
        cout << vec[i] << " ";      \
    }                               \
    cout << endl
#define input(vec, s, n)            \
    vector<int> vec(s + n);         \
    for (int i = s; i < s + n; i++) \
    {                               \
        cin >> vec[i];              \
    }
#define ini(_n) \
    int _n;     \
    cin >> _n;
#define inl(_n) \
    ll _n;      \
    cin >> _n;
#define go     \
    int tc;    \
    cin >> tc; \
    while (tc--)
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long int ll;

int main()
{
    // your code goes here

    /*

    We just need the frequency of all distinct elements

    say there are k uniq elements

    u1, u2, u3, ... uk
    with frequency
    f1, f2, f3....fk

    to create a subsequence

    we can choose u1 0 times, 1 times, ... f1 times
    => f1+1 options.

    hence overall = (f1+1)*(f2+1) .... *(fk+1) - 1 (1 case removed for empty subseq.)

    */

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int &i : a)
            cin >> i;

        map<int, int> freq;
        long long int ans = 1;
        int mod7 = 1e9 + 7;

        for (int i : a)
        {
            freq[i]++;
        }

        for (auto pii : freq)
        {
            int f = pii.second;
            ans *= (f + 1);
            ans %= mod7;
        }

        ans--;

        cout << ans << endl;
    }

    return 0;
}