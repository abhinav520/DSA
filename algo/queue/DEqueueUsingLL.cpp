#include <iostream>

using namespace std;
class Node{
public:
    int data;
    Node* next;
};
 
class DEQueue{
private:
    Node* front;
    Node* rear;
public:
    DEQueue();
    ~DEQueue();
    void display();
    void enqueueFront(int x);
    void enqueueRear(int x);
    int dequeueFront();
    int dequeueRear();
    bool isEmpty();
    bool isFull();
};

DEQueue::DEQueue(){
    front=rear=NULL;
}
DEQueue::~DEQueue(){
    Node* t= front;
    while(isEmpty()){
        front=front->next;
        delete t;
        t=front;
    }
}
bool DEQueue::isEmpty(){
    if(front==0){
        return true;
    }
    return false;
}
bool DEQueue::isFull(){
    Node* t=new Node;
    if(t==NULL){
        return true;
    }
    return false;
}
void DEQueue::display(){
    Node* t=front;
    while(t!=NULL){
        cout<<t->data<<" ";
        t=t->next;
    }
    cout<<endl;
}
void DEQueue::enqueueFront(int x){
    Node* enf=new Node;
    if(isFull()){
        cout<<"DEQueue Overflow";
        return;
    }
    enf->data=x;
    enf->next=front;
    if(isEmpty()){
        rear=front=enf;
    }
    else 
        front=enf;
    return;
}
void DEQueue::enqueueRear(int x){
    Node* enr=new Node;
    if(isFull()){
        cout<<"DEQueue Overflow";
        return;
    }
    enr->data=x;
    enr->next=NULL;
    if(isEmpty()){
        rear=front=enr;
    }
    else{
        rear->next=enr;
        rear=enr;
    }  
}

int DEQueue::dequeueFront(){
    int x=-1;
    Node* t=front;
    if(isEmpty()){
        cout<<"DEQueue Underflow";
        return x;
    }
    x=front->data;
    front=front->next;
    delete (t);
    return x;
}
int DEQueue::dequeueRear(){
    int x=-1;
    Node* t=rear, *tailptr=front;
    if(isEmpty()){
        cout<<"DEQueue Underflow";
        return x;
    }
    while(tailptr->next!=rear && tailptr!=rear){
        tailptr=tailptr->next;
    }
    rear=tailptr;
    x=t->data;
    tailptr->next=NULL;
    delete (t);
    return x;
}


int main() {
 
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6, 8};
 
    DEQueue deq;
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.enqueueRear(A[i]);
    }
    deq.display();
    deq.enqueueRear(11);
 
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        deq.dequeueFront();
    }
    deq.dequeueFront();
 
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.enqueueFront(B[i]);
    }
    deq.display();
    deq.enqueueFront(10);
    deq.enqueueFront(12);
 
    for (int i=0; i<sizeof(B)/sizeof(B[0]); i++){
        deq.dequeueRear();
    }
    deq.display();
    deq.dequeueRear();
    deq.dequeueRear();
 
    return 0;
}