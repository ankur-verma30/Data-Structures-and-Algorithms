#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class stack
{

    node *top;

public:
    stack()
    {
        top = NULL;
    }

    void push_node(int x);
    int pop_node();
    void display();
};

void stack::push_node(int x)
{
    node *t = new node;
    if (t == NULL)
        cout << "Stack is full!" << endl;
    else
    {

        t->data = x;
        t->next = top;
        top = t;
    }
}

int stack::pop_node()
{
    int x = -1;
    if (top == NULL)
    {
        cout << "the stack is empty" << endl;
    }
    else
    {
        x = top->data;
        node *t = top;
        top = top->next;
        delete t;
    }
    return x;
}

void stack::display()
{
    node *t = top;
    while (t != NULL)
    {
        cout << t->data << " ";
         t= t->next;
    }
    cout << endl;
}

int main()
{
stack stk;
stk.push_node(10);
stk.push_node(20);
stk.push_node(30);
stk.display();
stk.pop_node();
stk.display();

}
