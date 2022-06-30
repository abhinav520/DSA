#include <bits/stdc++.h>
using namespace std;

struct minqueue
{
  stack<pair<int, int>> s1, s2;
  void push(int new_element)
  {
    int minimum = s1.empty() ? new_element : min(new_element, s1.top().second);
    s1.push({new_element, minimum});
  }

  void pop()
  {
    if (s2.empty())
    {
      while (!s1.empty())
      {
        int element = s1.top().first;
        s1.pop();
        int minimum = s2.empty() ? element : min(element, s2.top().second);
        s2.push({element, minimum});
      }
    }
    int remove_element = s2.top().first;
    s2.pop();
  }

  int getMin()
  {
    int minimum;
    if (s1.empty() || s2.empty())
      minimum = s1.empty() ? s2.top().second : s1.top().second;
    else
      minimum = min(s1.top().second, s2.top().second);
    return minimum;
  }
};
struct minqueue
{
  stack<pair<int, int>> s1, s2;
  void push(int new_element)
  {
    int minimum = s1.empty() ? new_element : min(new_element, s1.top().second);
    s1.push({new_element, minimum});
  }

  void pop()
  {
    if (s2.empty())
    {
      while (!s1.empty())
      {
        int element = s1.top().first;
        s1.pop();
        int minimum = s2.empty() ? element : min(element, s2.top().second);
        s2.push({element, minimum});
      }
    }
    int remove_element = s2.top().first;
    s2.pop();
  }

  int getMin()
  {
    int minimum;
    if (s1.empty() || s2.empty())
      minimum = s1.empty() ? s2.top().second : s1.top().second;
    else
      minimum = min(s1.top().second, s2.top().second);
    return minimum;
  }
};
struct maxqueue
{
  stack<pair<int, int>> s1, s2;
  void push(int new_element)
  {
    int maximum = s1.empty() ? new_element : max(new_element, s1.top().second);
    s1.push({new_element, maximum});
  }

  void pop()
  {
    if (s2.empty())
    {
      while (!s1.empty())
      {
        int element = s1.top().first;
        s1.pop();
        int maximum = s2.empty() ? element : max(element, s2.top().second);
        s2.push({element, maximum});
      }
    }
    int remove_element = s2.top().first;
    s2.pop();
  }

  int getMax()
  {
    int maximum;
    if (s1.empty() || s2.empty())
      maximum = s1.empty() ? s2.top().second : s1.top().second;
    else
      maximum = max(s1.top().second, s2.top().second);
    return maximum;
  }
};

int main()
{
  minqueue minq;
  return 0;
}