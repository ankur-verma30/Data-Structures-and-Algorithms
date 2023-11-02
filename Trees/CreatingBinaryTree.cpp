#include <bits/stdc++.h>
//mostly it is a type of the c language program 
using namespace std;
struct Node
{
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
};
struct Queue
{
    int size;
    int front;
    int rear;
    Node **Q;
};

void CreateQueue(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (Node **)malloc(q->size * sizeof(Node *));
}

void Enqueue(struct Queue *q, Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        cout << "Queue is full!" << endl;
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int IsEmpty(struct Queue q)
{
    return q.front == q.rear;
}

Node *dequeue(struct Queue *q)
{
    Node *x = NULL;
    if (q->front == q->rear)
        cout << "Queue is empty " << endl;
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

struct Node *root = NULL;

void CreateBinaryTree()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    CreateQueue(&q, 100);
    cout << "Enter the root value of the binary tree " << endl;
    cin >> x;
    root = new Node;
    root->data = x;
    root->leftChild = root->rightChild = NULL;
    Enqueue(&q, root);
    while (!IsEmpty(q))
    {
        p = dequeue(&q);
        cout << "Enter the left child of " << p->data << endl;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->leftChild = t->rightChild = NULL;
            p->leftChild = t;
            Enqueue(&q, t);
        }
        cout << "Enter the Right child of " << p->data << endl;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->leftChild = t->rightChild = NULL;
            p->rightChild = t;
            Enqueue(&q, t);
        }
    }
}

void Preorder(struct Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        Preorder(p->leftChild);
        Preorder(p->rightChild);
    }
}

void PostOrder(struct Node *p)
{
    if (p)
    {
        PostOrder(p->leftChild);
        PostOrder(p->rightChild);
        cout << p->data << " ";
    }
}

int main()
{
    CreateBinaryTree();
    Preorder(root);
    cout << endl;
    PostOrder(root);
}