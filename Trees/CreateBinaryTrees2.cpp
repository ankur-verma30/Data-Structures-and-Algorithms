#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    Node *LeftChild;
    Node *RightChild;
    int Data;
};
class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new Node *[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new Node *[this->size];
    }
    void enqueue(Node *x);
    Node *dequeue();
    void display();
    int IsEmpty();
};

int Queue::IsEmpty()
{
    return this->front == this->rear;
}

void Queue::enqueue(Node *x)
{
    if (rear == size - 1)
        cout << "Queue is full!" << endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}
Node *Queue::dequeue()
{
    Node *x = NULL;
    if (front == rear)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}
void Queue::display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        cout << Q[i] << " " << endl;
    }
    cout << endl;
}

class Tree
{
public:
    Node *root; // if we are only writing the dummy function we can make the root private
    Tree()
    {
        root = NULL;
    }
    void CreateBinaryTree();
    void PreorderTraversal(Node *p);
    void PreorderTraversal() // dummy function
    {
        PreorderTraversal(root);
    };
    void PostorderTraversal(Node *p);
    void PostorderTraversal()
    {
        PostorderTraversal(root);
    };
    void InorderTraversal(Node *p);
    void InorderTraversal()
    {
        InorderTraversal(root);
    };
    void LevelOrderTraversal(Node *p);
    void LevelOrderTraversal()
    {
        LevelOrderTraversal(root);
    };
    int HeightOfBinaryTree(Node *root);
    int HeightOfBinaryTree()
    {
        HeightOfBinaryTree(root);
    }
};

void Tree::CreateBinaryTree()
{
    Node *p, *t;
    int x;
    Queue q(100);
    // CreateQueue(&q, 100);
    cout << "Enter the root value of the binary tree " << endl;
    cin >> x;
    root = new Node;
    root->Data = x;
    root->LeftChild = root->RightChild = NULL;
    q.enqueue(root);
    while (!q.IsEmpty())
    {
        p = q.dequeue();
        cout << "Enter the left child of " << p->Data << endl;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->Data = x;
            t->LeftChild = t->RightChild = NULL;
            p->LeftChild = t;
            q.enqueue(t);
        }
        cout << "Enter the Right child of " << p->Data << endl;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->Data = x;
            t->LeftChild = t->RightChild = NULL;
            p->RightChild = t;
            q.enqueue(t);
        }
    }
}

void Tree::PreorderTraversal(Node *p)
{
    if (p)
    {
        cout << p->Data << " ";
        PreorderTraversal(p->LeftChild);
        PreorderTraversal(p->RightChild);
    }
}
void Tree::PostorderTraversal(Node *p)
{
    if (p)
    {
        PostorderTraversal(p->LeftChild);
        PostorderTraversal(p->RightChild);
        cout << p->Data << " ";
    }
}
void Tree::InorderTraversal(Node *p)
{
    if (p)
    {
        InorderTraversal(p->LeftChild);
        cout << p->Data << " ";
        InorderTraversal(p->RightChild);
    }
}

void Tree::LevelOrderTraversal(Node *p)
{
    Queue q(100);
    cout << root->Data << " " << endl;
    q.enqueue(root);
    while (!q.IsEmpty())
    {
        root = q.dequeue();
        if (root->LeftChild)
        {
            cout << root->LeftChild->Data;
            q.enqueue(root->LeftChild);
        }
        if (root->RightChild)
        {
            cout << root->RightChild->Data;
            q.enqueue(root->RightChild);
        }
    }
}

int Tree::HeightOfBinaryTree(Node *root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = HeightOfBinaryTree(root->LeftChild);
    y = HeightOfBinaryTree(root->RightChild);
    if (x > y)
        return x + 1;
    return y + 1;
}
int main()
{
    Tree T;
    T.CreateBinaryTree();
    cout << endl;
    cout << "Pre Order Traversal of the tree" << endl;
    T.PreorderTraversal(T.root);
    cout << endl;
    cout << "Post Order Traversal of the tree" << endl;
    T.PostorderTraversal(T.root);
    cout << endl;
    cout << "InOrder Traversal of the tree" << endl;
    T.InorderTraversal(T.root);
    cout << endl;
    cout << "Level Order Traversal of the tree" << endl;
    T.LevelOrderTraversal(T.root);
    cout << endl;
    cout << "the height of the tree is " << T.HeightOfBinaryTree(T.root);
    return 0;
}