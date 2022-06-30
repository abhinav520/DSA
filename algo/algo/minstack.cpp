#include <bits/stdc++.h>
using namespace std;

struct minstack{
  stack<pair<int, int>> stk;
  void push(int val)
  {
    int new_min = stk.empty() ? val : min(val, stk.top().second);
    stk.push({val, new_min});
  }

  void pop()
  {
    stk.pop();
  }

  int top()
  {
    return stk.top().first;
  }

  int getMin()
  {
    return stk.top().second;
  }
};


struct maxstack{
  stack<pair<int, int>> stk;
  void push(int val)
  {
    int new_max = stk.empty() ? val : max(val, stk.top().second);
    stk.push({val, new_max});
  }

  void pop()
  {
    stk.pop();
  }

  int top()
  {
    return stk.top().first;
  }

  int getMin()
  {
    return stk.top().second;
  }
};




int main()
{
  minstack minstk;
  return 0;
}