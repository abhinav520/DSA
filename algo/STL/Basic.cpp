#include <iostream>
#include <climits>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

Node* create(Node* head,int A[], int n)
{ //inserting from starting
    Node *temp, *last;

    head = new Node();
    head->data = A[0];
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        temp = new Node();
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
    return head;
}

void display(Node *ptr)
{
    while (ptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

bool isIdentical(Node* a, Node*b){
    while(a!=NULL && b!=NULL){
        if(a->data!=b->data){
            return false;
        }
        a=a->next;
        b=b->next;
    }
    return(a==NULL && b==NULL);
}

Node* merge(Node* first,Node* second){
    Node* third,*last;
    //for first node
    if(first->data < second->data){
        third=first;
        last=first;
        first=first->next;
        last->next=0;
    }
    else{
        third=second;
        last=second;
        second=second->next;
        last->next=0;
    }
    //for both list
    while(first!=0 && second!=0){
        if(first->data < second->data){
            last->next=first;
            last=first;
            first=first->next;
            last->next=0;
        }
        else{
            last->next=second;
            last=second;
            second=second->next;
            last->next=0;
        }
    }
    // for same lenght perform below steps
    // if(p)last->next=p;
    // if(q)last->next=q;

    //for extra node of large list (different length)
    if(second==NULL){
        while(first){
            last->next=first;
            last=first;
            first=first->next;
            last->next=0;
        }
        
    }
    else{
        while(second){
            last->next=second;
            last=second;
            second=second->next;
            last->next=0;
        };
    }
    return third;
}

int main()
{
    Node* hfirst=0;
    int A1[] = {2,8,10,15};
    hfirst=create(hfirst,A1, 4);
    display(hfirst);
    cout << endl;

    Node* hsecond=0;
    int A2[] = {4,7,12,14,20,21};
    hsecond=create(hsecond,A2, 6);
    display(hsecond);
    cout << endl;

    display(merge(hfirst,hsecond));
    cout << endl;
    return 0;
}