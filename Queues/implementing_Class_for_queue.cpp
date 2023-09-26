#include <iostream>

using namespace std;

class Queue
{
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue()
    {
        size = 10;
        front = rear = -1;
        Q = new int[size];
    }

    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        Q = new int[size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::display()
{
    for (int i = front + 1; i <= rear; i++)
        cout << Q[i] << " ";
    cout << endl;
}

void Queue::enqueue(int x)
{
    if (rear == size - 1)
        cout << "the queue is full" << endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}
int Queue::dequeue()
{
    int x = -1;
    if (rear == front)
        cout << "the queue is empty" << endl;
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}

int main()
{

    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    cout << "Deleted element from the queue is " << q.dequeue() << endl;
    q.display();

    return 0;
}