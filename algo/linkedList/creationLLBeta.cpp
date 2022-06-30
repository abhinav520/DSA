#include <iostream>
#include <climits>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
} * first; //first=head

void create(int A[], int n)
{ //inserting from starting
    Node *temp, *last;

    first = new Node();
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = new Node();
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void RevCreate(int A[], int n)
{ //inserting from end
    Node *temp, *last;
    last = new Node;
    last->data = A[n - 1];
    last->next = 0;
    first = last;

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[n - 1 - i];
        temp->next = first;
        first = temp;
    }
}

void display(Node *ptr)
{
    while (ptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

//Displaying thru rec (in reverse)
void Rdisplay(Node *ptr)
{
    if (ptr != 0)
    {
        Rdisplay(ptr->next);
        cout << ptr->data << " ";
    }
}

int count(Node *ptr)
{
    int len = 0;
    while (ptr)
    {
        len++;
        ptr = ptr->next;
    }
    return len;
}
int Rcount(Node *ptr)
{
    if (ptr)
    {
        return 1 + Rcount(ptr->next);
    }
    else
        return 0;
}

int sum(Node *ptr)
{
    int _sum = 0;
    while (ptr)
    {
        _sum += ptr->data;
        ptr = ptr->next;
    }
    return _sum;
}
int Rsum(Node *ptr)
{
    if (ptr)
    {
        return ptr->data + Rsum(ptr->next);
    }
    else
        return 0;
}

int max(Node *ptr)
{
    int max = ptr->data;
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
int Rmax(Node *ptr)
{ //Tail rec
    int mx = 0;
    if (ptr)
    {
        mx = Rmax(ptr->next);
        return ((mx > (ptr->data)) ? mx : (ptr->data));
    }
    // if(ptr){
    //     int mx=max(ptr->data,Rmax(ptr->next));
    //     return mx;
    // }
    else
        return INT_MIN;
}
int min(Node *ptr)
{
    int min = ptr->data;
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
int Rmin(Node *ptr)
{ //Tail rec
    int mn = 0;
    if (ptr)
    {
        mn = Rmin(ptr->next);
        return ((mn < (ptr->data)) ? mn : (ptr->data));
    }
    // if(ptr){
    //     int mx=max(ptr->data,Rmax(ptr->next));
    //     return mx;
    // }
    else
        return INT_MAX;
}

Node *Lsearch(Node *ptr, int key)
{
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
Node *RSearch(Node *ptr, int key)
{
    if (ptr == 0)
    {
        return NULL;
    }
    if (ptr->data == key)
    {
        return ptr;
    }
    else
    {
        return RSearch(ptr->next, key);
    }
}
//Improving Linear Search- 1)Transposition 2)Move to head/front (former is not good in linked list)
Node *ImprovedLsearch(Node *ptr, int key)
{
    Node *tailptr = NULL;
    while (ptr)
    {
        if (ptr->data == key)
        {
            tailptr->next = ptr->next;
            ptr->next = first;
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


void reverse(Node* p){     //reversing using sliding pointers
    Node *q=0,*r=0;
    while(p!=0){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void Rreverse(Node* tailptr,Node* hptr){
    if(hptr!=NULL){
        Rreverse(hptr,hptr->next);
        hptr->next=tailptr;
    }
    else{
        first=tailptr;
    }
}
// bool isIdentical(Node* a, Node*b){
//     while(a!=NULL && b!=NULL){
//         if(a->data!=b->data){
//             return false;
//         }
//         a=a->next;
//         b=b->next;
//     }
//     return(a==NULL && b==NULL);
// }

Node* midNode(Node* ptr){
    //if one pointer jumps two steps and second pointer jump only one step then when former reaches end then latter will reach at the mid---> two pointer approach
    Node* fast=ptr, *slow=ptr;
    while(fast!=NULL){
        fast=fast->next;
        fast= (fast==0) ? NULL : fast->next;
        slow=slow->next;
    }
    return slow;
}

void Insert(Node *ptr, int pos, int data)
{
    Node *temp;
    temp = new Node();
    if (pos < 0 || pos > count(ptr))
    {
        return;
    }
    if (pos == 1)
    {
        temp->data = data;
        temp->next = ptr->next;
        first = temp;
    }
    for (int i = 0; i < (pos); i++)
    {
        ptr = ptr->next;
    }
    temp->data = data;
    temp->next = ptr->next;
    ptr->next = temp;
}

bool isSorted(Node* ptr){
    int x=ptr->data;
    ptr=ptr->next;
    while(ptr){
        if(ptr->data < x){
            return false;
        }
        x=ptr->data;
        ptr=ptr->next;
    }
    return true;
}

int Delete(Node *ptr, int pos)
{
    Node *tailptr = 0;
    int x = -1;
    if (pos == 1)
    {
        first = first->next;
        x = ptr->data;
        delete (ptr);
        return x;
    }
    for (int i = 0; i < pos; i++)
    {
        tailptr = ptr;
        ptr = ptr->next;
    }
    x = ptr->data;
    tailptr -> next = ptr->next;
    delete (ptr);
    return x;
}
void DeleteVal(Node* ptr,int val){
    if(first->data==val){
        first=first->next;
        delete (ptr);
    }
    else{
        Node* tailptr=0;
        while(ptr!=NULL && ptr->data!=val){
            tailptr=ptr;
            ptr=ptr->next;
        }
        if(ptr->data==val){
            tailptr->next=ptr->next;
            delete (ptr);
        }
        else{
            cout<<"\nSorry, Element is not present or already deleted from list\n";
        }
    }

}
void erase(Node* ptr){
    Node* temp;
    while(ptr){
        temp=ptr;
        ptr=ptr->next;
        delete(temp);
    }
    delete (ptr);
}



int main()
{
    // int n;
    // cout<<"Enter the number of elements: ";
    // cin>>n;
    // int A[n];
    // for(int i=0;i<n;i++){
    //     cin>>A[i];
    // }
    //create(A,n);
    //display(first);
    // RevCreate(A,n);
    // Rdisplay(first);

    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);
    display(first);
    cout << endl;
    // cout << "Total Elements in list: " << Rcount(first) << endl;
    // cout << "Sum of all elements is " << sum(first) << endl;
    // cout << "Min of all elements is " << Rmin(first) << endl;
    // cout << "Enter the elements to be searched: ";
    // int key;
    // cin >> key;
    // Node *ptr = ImprovedLsearch(first, key);
    // if (ptr == 0)
    // {
    //     cout << "Element not found" << endl;
    // }
    // else
    // {
    //     cout << "Element found at address : " << ptr << endl;
    //     cout << "Element is : " << ptr->data << endl;
    // }
    // display(first);

    // Rreverse(0,first);
    // display(first);

    // cout<<(midNode(first))->data<<endl;
    // cout<<(midNode(first));

    DeleteVal(first,2);
    display(first);
    erase(first);
    cout<<"\nHappy Programming :)";

    return 0;
}