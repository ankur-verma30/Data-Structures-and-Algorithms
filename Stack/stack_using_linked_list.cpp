#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
} *top = NULL;

void display_node()
{
     struct node *p;
     p=top;
    while (p != NULL)
    {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL";
    cout << endl;
}

void push_node(int x)
{

    struct node *t = new node;
    if (t == NULL)
        cout << "the stack is full!" << endl;
    else
    {
        t->data=x;
        t->next = top;
        top = t;
    }
}
int pop_node()
{
    int x = -1;
    struct node *p ;
    if (top == NULL)
        cout << "the stack is empty!" << endl;
    else
    {
        p = top;
        top = top->next;
        x = p->data;
        delete[] p;
    }
    return x;
}
int main()
{

    push_node(10);
    push_node(20);
    push_node(30);
    display_node();
    cout << "After deleting one element " << pop_node() << endl;
    display_node();
    return 0;
}