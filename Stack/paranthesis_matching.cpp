#include <iostream>
using namespace std;

struct node
{
    char data;
    struct node *next;
} *top = NULL;

void display_node()
{
    struct node *p;
    p = top;
    while (p != NULL)
    {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL";
    cout << endl;
}

void push_node(char x)
{

    struct node *t = new node;
    if (t == NULL)
        cout << "the stack is full!" << endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
char pop_node()
{
    char x;
    struct node *p;
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

bool Isbalanced(string &exp)
{
    for(int i = 0; i <exp.size(); i++){
        if(exp[i] == '(')
        push_node(exp[i]);
        else if(exp[i]==')')
        {
            if(top==NULL)
            return false;
            pop_node();
        }

    }
    if(top==NULL)
    return true;
    else 
    return false;
}

int main()
{

    string exp = "((a+b)*(c-d)))";

    cout << boolalpha;
    cout << "the string is balanced " << Isbalanced(exp);
    return 0;
}
