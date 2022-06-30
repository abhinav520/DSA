#include <iostream>
using namespace std;
class Stack
{
private:
    int size;
    int top;
    int *s;

public:
    Stack(int size);
    ~Stack();
    bool isEmpty();
    bool isFull();
    void push(int value);
    int pop();
    int seek(int pos);
    int stackTop();
    void display();
};

Stack::Stack(int size)
{
    this->size=size;
    top = -1;
    s = new int[size];
}

Stack::~Stack()
{
    delete[] s;
}

bool Stack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::isFull()
{
    if (top == size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack::push(int value)
{
    if (isFull())
    {
        cout << "Stack Overflow!!" << endl;
    }
    else
    {
        top++;
        s[top] = value;
    }
}

int Stack::pop()
{
    int x = -1;
    if (isEmpty())
    {
        cout << "Stack Underflow!!" << endl;
    }
    else
    {
        x = s[top];
        top--;
    }
    return x;
}

int Stack::seek(int pos)
{
    if ((top + 1 - pos) < 0 || pos <= 0)
    {
        cout << "Invalid position!!" << endl;
        return -1;
    }
    return s[top + 1 - pos];
}

int Stack::stackTop()
{
    return isEmpty() ? -1 : s[top];
}

void Stack::display()
{
    cout << s[top] << "\t<--top" << endl;
    for (int i = (top)-1; i >= 0; i--)
    {
        cout << s[i] << endl;
    }
}

int main()
{
    int size;
    cout << "Enter the size of stack: ";
    cin >> size;
    Stack stk(size);
    stk.push(20);
    stk.push(2);
    stk.push(99);
    stk.push(116);
    stk.push(10);
    stk.display();
    //stk.push(0);
    stk.pop();
    stk.display();
    cout << "seeking at pos 2: " << stk.seek(2) << endl;
    cout << "StackTop: " << stk.stackTop() << endl;

    return 0;
}