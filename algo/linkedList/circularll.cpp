#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;
};

template <class T>
class LinkedList
{
private:
    Node<T> *first;
public:
    LinkedList() { first = NULL; }
    LinkedList(T A[], int n);
    ~LinkedList();

    void display();
    void Insert(int index, T data);
    T Delete(int pos);
    void DeleteVal(T val);
    bool isSorted();
    int length();
    T sum();
    T min();
    T max();
    Node<T> *Lsearch(T key);
    Node<T> *ImprovedLsearch(T key);
    void reverse();
    Node<T> *midNode();
};

template <class T>
LinkedList<T>::LinkedList(T A[], int n)
{
    Node<T> *temp, *last;

    first = new Node<T>();
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = new Node<T>();
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
    last->next=first;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *temp,*curr;
    curr=first->next;
    while(curr!=first)
    {
        temp = curr;
        curr = curr->next;
        delete (temp);
    }
    delete (first);
}


template <class T>
void LinkedList<T>::display()
{
    if(head==0){
        cout<<"List is empty";
    }
    Node<T> *ptr = first;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }while(ptr!=head);
    cout<<endl;
}

template <class T>
void LinkedList<T>::Insert(int index, T data)
{
    Node<T> *temp, *ptr = first;
    temp = new Node<T>();
    if (index < 0 || index > length())
    {
        return;
    }
    if (index == 0)
    {
        temp->data=data;
        if(head==NULL){
            temp->next=temp;
            head=temp;  // lastly added before midsem may be wrong
        }
        else{
            while(ptr->next!=head){
                ptr=ptr->next;
            }
            ptr->next=temp;
            temp->next=head;
            // temp->next = ptr->next;
            // ptr->next = temp;
            head=temp;
        }
    }
    for (int i = 0; i < (index - 1); i++)
    {
        ptr = ptr->next;
    }
    temp->data = data;
    temp->next = ptr->next;
    ptr->next = temp;
}

template <class T>
T LinkedList<T>::Delete(int pos)
{
    Node<T> *tailptr = 0, *ptr = first;
    int x = -1;
    if (pos == 1)
    {
        while(ptr->next!=head){
            ptr=ptr->next;
        }
        if(ptr==first){
            delete first;
            first=NULL;
        }
        x = first->data;
        ptr->next = first->next;
        delete (first);
        first=ptr;
        return x;
    }
    for (int i = 0; i < pos - 1; i++)
    {
        tailptr = ptr;
        ptr = ptr->next;
    }
    x = ptr->data;
    tailptr->next = ptr->next;
    delete (ptr);
    return x;
}

template <class T>
void LinkedList<T>::DeleteVal(T val)
{
    Node<T> *ptr = first;
    if (first->data == val)
    {
        first = first->next;
        delete (ptr);
    }
    else
    {
        Node<T> *tailptr = 0;
        while (ptr != NULL && ptr->data != val)
        {
            tailptr = ptr;
            ptr = ptr->next;
        }
        if (ptr != 0)
        {
            tailptr->next = ptr->next;
            delete (ptr);
        }
        else
        {
            cout << "\nSorry, Element is not present or already deleted from list\n";
        }
    }
}

template <class T>
bool LinkedList<T>::isSorted()
{
    Node<T> *ptr = first;
    T x = ptr->data;
    ptr = ptr->next;
    while (ptr)
    {
        if (ptr->data < x)
        {
            return false;
        }
        x = ptr->data;
        ptr = ptr->next;
    }
    return true;
}

template <class T>
int LinkedList<T>::length()
{
    Node<T> *ptr = first;
    int len = 0;
    while (ptr)
    {
        len++;
        ptr = ptr->next;
    }
    return len;
}

template <class T>
T LinkedList<T>::sum()
{
    Node<T> *ptr = first;
    T _sum = 0;
    while (ptr)
    {
        _sum += ptr->data;
        ptr = ptr->next;
    }
    return _sum;
}

template <class T>
T LinkedList<T>::min()
{
    Node<T> *ptr = first;
    T min = ptr->data;
    ptr = ptr->next;
    while (ptr)
    {
        if (min > ptr->data)
        {
            min = ptr->data;
        }
        ptr = ptr->next;
    }
    return min;
}

template <class T>
T LinkedList<T>::max()
{
    Node<T> *ptr = first;
    T max = ptr->data;
    ptr = ptr->next;
    while (ptr)
    {
        if (max < ptr->data)
        {
            max = ptr->data;
        }
        ptr = ptr->next;
    }
    return max;
}

template <class T>
Node<T> *LinkedList<T>::Lsearch(T key)
{
    Node<T> *ptr = first;
    while (ptr)
    {
        if (key == ptr->data)
        {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

template <class T>
Node<T> *LinkedList<T>::ImprovedLsearch(T key)
{
    Node<T> *ptr = first;
    Node<T> *tailptr = NULL;
    while (ptr)
    {
        if (ptr->data == key)
        {
            tailptr->next = ptr->next;
            ptr->next = first->next;
            first = ptr;
            return ptr;
        }
        else
        {
            tailptr = ptr;
            ptr = ptr->next;
        }
    }
    return NULL;
    //return ptr
}

template <class T>
void LinkedList<T>::reverse()
{
    Node<T> *p = first; //reversing using sliding pointers
    Node<T> *q = 0, *r = 0;
    while (p != 0)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

template <class T>
Node<T>* LinkedList<T>::midNode(){
    //if one pointer jumps two steps and second pointer jump only one step then when former reaches end then latter will reach at the mid---> two pointer approach
    Node<T>* fast=first, *slow=first;
    while(fast!=NULL){
        fast=fast->next;
        fast= (fast==0) ? NULL : fast->next;
        slow=slow->next;
    }
    return slow;
}


int main()
{
    int A[] = {1, 2, 3, 4, 5};
    LinkedList<int> l(A, 5);
    l.display();
    l.Insert(5, 10);
    l.display();
    cout<<"The length of linked list: "<<l.length()<<endl;
    cout<<"The min element of linked list: "<<l.min()<<endl;
    cout<<"The max element of linked list: "<<l.max()<<endl;
    cout<<"The sum of all element in linked list: "<<l.sum()<<endl;
    cout<<"isSorted: "<<l.isSorted()<<endl;
    cout<<"Mid value: "<<l.midNode()->data<<endl;
    int key;
    cout<<"Enter the value to be searched: ";
    cin>>key;
    cout<<l.Lsearch(key)<<endl;
    cout<<"Linked list in reverse order: ";
    l.reverse();
    l.display();
    cout<<l.Delete(3)<<endl;
    l.display();
    l.DeleteVal(10);
    l.display();
    
    return 0;
}