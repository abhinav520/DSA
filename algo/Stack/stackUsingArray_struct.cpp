#include <iostream>
using namespace std;
// class Stack{
// public:
//     int size;
//     int top;
//     int *s;
// };
struct Stack{
    int size;
    int top;
    int *s;
};
void create(Stack *st){
    cout<<"Enter the size of stack: ";
    cin>>(st->size);
    st->top=-1;
    st->s= new int[st->size];
}
bool isEmpty(Stack* st){
    if(st->top==-1){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(Stack* st){
    if((st->top)==((st->size)-1)){
        return true;
    }
    else{
        return false;
    }
}

void push(Stack* st,int value){
    if(isFull(st)){
        cout<<"Stack Overflow!!"<<endl;
    }
    else{
        st->top++;
        st->s[st->top]=value;
    }
}

int pop(Stack* st){
    int x=-1;
    if(isEmpty(st)){
        cout<<"Stack Underflow!!"<<endl;
    }
    else{
        x=st->s[st->top];
        st->top--;
    }
    return x;
}

int seek(Stack* st,int pos){
    if((st->top+1-pos)<0 || pos<=0){
        cout<<"Invalid position!!"<<endl;
        return -1;
    }
    return st->s[st->top+1-pos];
}

int stackTop(Stack* st){
    return isEmpty(st)?-1:st->s[st->top];
}

void display(Stack* st){
    cout<<st->s[st->top]<<"\t<--top"<<endl;
    for(int i=(st->top)-1;i>=0;i--){
        cout<<st->s[i]<<endl;
    }
}


int main()
{
    Stack st;
    create(&st);
    push(&st,20);
    push(&st,2);
    push(&st,99);
    push(&st,116);
    push(&st,10);
    display(&st);
    push(&st,0);
    pop(&st);
    display(&st);
    cout<<"seeking at pos 2: "<<seek(&st,2)<<endl;
    cout<<"StackTop: "<<stackTop(&st)<<endl;

    return 0;
}