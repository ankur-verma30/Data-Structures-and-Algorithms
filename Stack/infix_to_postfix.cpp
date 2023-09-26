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
        delete p; // Use delete instead of delete[]
    }
    return x;
}

int Precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

bool IsOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return false;
    return true;
}

string InfixToPostfix(string &infix) // Changed return type to string
{
    string post = ""; // Use a string to store the postfix expression
    int i = 0;

    // Initialize the stack with a '#' character
    push_node('#');

    while (infix[i] != '\0')
    {
        if (IsOperand(infix[i]))
        {
            post += infix[i]; // Append operand to the postfix string
            i++;
        }
        else
        {
            if (Precedence(infix[i]) > Precedence(top->data))
            {
                push_node(infix[i]);
                i++;
            }
            else
            {
                post += pop_node(); // Append popped operator to the postfix string
            }
        }
    }

    // Pop any remaining operators from the stack and append to postfix string
    while (top != NULL && top->data != '#')
    {
        post += pop_node();
    }

    return post;
}

int main()
{
    string str = "a+b*c";
    string res = InfixToPostfix(str);
    cout << "The result is " << res << endl;
    return 0;

}


