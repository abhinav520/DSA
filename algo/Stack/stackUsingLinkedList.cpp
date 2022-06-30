#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
};

template <class T>
class Stack
{
private:
    Node<T> *top;

public:
    Stack();
    ~Stack();
    void push(T x);
    T pop();
    T peek(int index);
    bool isEmpty();
    bool isFull();
    T stackTop();
    void display();
};

template <class T>
Stack<T>::Stack()
{
    top = NULL;
}

template <class T>
Stack<T>::~Stack()
{
    Node<T> *temp;
    while (top)
    {
        temp = top;
        top = top->next;
        delete (temp);
    }
}

template <class T>
void Stack<T>::push(T x)
{
    Node<T> *temp = new Node<T>();
    if (temp == NULL)
    {
        cout << "Stack Overflow!!" << endl;
    }
    else
    {
        temp->data = x;
        temp->next = top;
        top = temp;
    }
}

template <class T>
T Stack<T>::pop()
{
    T x = -1;
    if (top == 0)
    {
        cout << "Stack Underflow!!";
    }
    else
    {
        Node<T> *t = top;
        x = top->data;
        top = top->next;
        delete t;
    }
    return x;
}
template <class T>
bool Stack<T>::isEmpty()
{
    return (top) ? false : true;
}
template <class T>
bool Stack<T>::isFull()
{
    Node<T> *ptr = new Node<T>;
    if (ptr == 0)
    {
        return true;
    }
    else
        return false;
}
template <class T>
T Stack<T>::stackTop()
{
    return (top) ? top->data : -1;
}
template <class T>
T Stack<T>::peek(int index)
{
    if (isEmpty())
    {
        cout << "Invalid Index!!";
        return -1;
    }
    else
    {
        Node<T> *ptr = top;
        for (int i = 1; ptr && i < index; i++)
        {
            ptr = ptr->next;
        }
        if (ptr != NULL)
        {
            return ptr->data;
        }
        else
        {
            return -1;
        }
    }
}
template <class T>
void Stack<T>::display()
{
    if (top)
    {
        cout << top->data << "\t<--top";
        Node<T> *ptr = top->next;
        while (ptr)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
}

// int main()
// {
//     int A[] = {1, 3, 5, 7, 9};
//     Stack<int> stk;
//     // Populate stack
//     for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
//     {
//         stk.push(A[i]);
//     }
//     stk.display();
//     // Pop out elements from stack
//     cout << "Popped: " << flush;
//     for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
//     {
//         cout << stk.pop() << ", " << flush;
//     }
//     cout << endl;
//     stk.display();
//     // Underflow
//     cout << stk.pop() << endl;
//     return 0;
// }