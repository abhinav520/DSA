#include <iostream>
using namespace std;
struct Circularqueue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(Circularqueue *q, int size)
{
    q->size = size+1;    //1 space for front
    q->front = q->rear = 0;
    q->Q = new int[size+1];
}
int enqueue(Circularqueue *q, int newVal)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        cout << "Queue Overflow";
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = newVal;
    }
}
int dequeue(Circularqueue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        cout << "Queue is Empty\n";
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}
void Display(Circularqueue q)
{
    int i = q.front + 1;
    do
    {
        cout << q.Q[i] << " ";
        i = (i + 1) % (q.size);
    } while (i != (q.rear + 1) % q.size);
}
int main()
{
    Circularqueue que;
    int size = 0;
    cout << "Enter the size of queue";
    cin >> size;
    create(&que, size);
    enqueue(&que, 10);
    enqueue(&que, 20);
    enqueue(&que, 30);
    enqueue(&que, 40);
    enqueue(&que, 50);
    enqueue(&que, 60);

    cout<<"The deleted value is "<<dequeue(&que)<<endl;

    Display(que);
    return 0;
}