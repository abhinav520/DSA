#include <bits/stdc++.h>
using namespace std;
struct typ
{
    int i, val, next;
} t2, t3, t5;
class Solution
{
public:

     int nthUglyNum(int n) {                  //O(>nlogn & <O(n^2))  brute force
        // 1 is already ugly start with 1
        int num = 1;
        int count  = 1;
        
        while (count < n) {
            // Increment the num so that it will be start at 2 in
            // beginining
            num++;
            
            int temp = num;
            // checking whether the number is palindrome or not
            // Check if the number is divisible by 2, 3, 5
            // If so the result will be 1 where 1 is always
            // an ugly number
            for (int factor : {2, 3, 5}) {
                while (temp % factor == 0) {
                    temp = temp / factor;
                }
            }
            count += temp == 1;
        }
        
        // num points to the nth ugly number
        return num;
    }

    int nthUglyNumber(int n)            //O(nlogn)  (use of stl)
    {
        set<long long int> ugly;
        // ugly.insert(1);
        long long int num = 1;
        n--;
        while (n--)
        {
            ugly.insert(2 * num);
            ugly.insert(3 * num);
            ugly.insert(5 * num);
            auto it = ugly.begin();
            num = *it;
            ugly.erase(it);
        }
        return num;
    }
    int nthUgly(int n)                  //O(N) (efficient)
    {
        pair<int, int> p2(1, 2), p3(1, 3), p5(1, 5);
        int dp[n + 1];
        dp[1] = 1;
        int next_mul_2 = dp[p2.first] * 2;
        int next_mul_3 = dp[p3.first] * 3;
        int next_mul_5 = dp[p5.first] * 5;
        for (int i = 2; i <= n; i++)
        {
            int temp = min(min(p2.second, p3.second), p5.second);
            dp[i] = temp;
            if (temp == next_mul_2)
            {
                p2.first++;
                next_mul_2 = dp[p2.first] * 2;
                p2.second = next_mul_2;
            }
            if (temp == next_mul_3)
            {
                p3.first++;
                next_mul_3 = dp[p3.first] * 3;
                p3.second = next_mul_3;
            }
            if (temp == next_mul_5)
            {
                p5.first++;
                next_mul_5 = dp[p5.first] * 5;
                p5.second = next_mul_5;
            }
        }
        return dp[n];
    }
};
int main()
{
    int n;
    cin >> n;
    Solution ob;
    cout << ob.nthUgly(n);
    return 0;
}