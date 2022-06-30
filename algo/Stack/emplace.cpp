#include <iostream>
#include <stack>

using namespace std;

int main(void) {
   stack<int> s;

   for (int i = 0; i < 5; ++i)
      // s.push(i + 1);
      s.emplace(i + 1);

   while (!s.empty()) {
      cout << s.top() << endl;
      s.pop();
   }

   return 0;
}