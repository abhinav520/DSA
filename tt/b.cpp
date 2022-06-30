#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        int sm = INT_MAX, mx = INT_MIN;
        for (auto &x : nums)
        {
            sm = min(sm, x);
            mx = max(mx, x);
        }
        if (sm > 1)
            return 1;
        if (sm <= 1 and mx == sm + n - 1)
        {
            return mx + 1;
        }
        vector<bool> f(n + 1, false);
        for (auto &x : nums)
        {
            if (x <= 0 and x > n)
                continue;
            f[x] = true;
        }
        for (int i = 1; i < n + 1; i++)
        {
            if (!f[i])
                return i;
        }
        return 1;
    }
};