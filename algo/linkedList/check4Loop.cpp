#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
}*head;

Node* create(int A[], int n)
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

bool isLoop(){
    Node* slowptr=head,*fastptr=head;
    do{
        slowptr=slowptr->next;
        fastptr=fastptr->next;
        fastptr= (fastptr==0) ? NULL : fastptr->next;
    }while(slowptr!=fastptr && slowptr && fastptr!=0);

    return (slowptr==fastptr)?true:false;
}

void removeLoop(){
    Node* slowptr=head,*fastptr=head;
    do{
        slowptr=slowptr->next;
        fastptr=fastptr->next;
        fastptr= (fastptr==0) ? NULL : fastptr->next;
    }while(slowptr!=fastptr && slowptr && fastptr!=0);
    slowptr=head;
    while(slowptr!=fastptr){
        slowptr=slowptr->next;
        fastptr=fastptr->next;
    }
    while(fastptr->next!=slowptr){
        fastptr=fastptr->next;
    }
    fastptr->next=0;
}

int main()
{
    int A[]={10,20,30,40,50};
    create(A,5);
    Node *t1, *t2;
    t1=head->next->next;
    t2=head->next->next->next->next;
    t2->next=t1;
    removeLoop();
    display(head);
    cout<<endl<<isLoop();
    return 0;
}