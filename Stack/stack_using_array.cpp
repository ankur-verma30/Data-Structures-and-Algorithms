#include <iostream>

using namespace std;
struct stack
{
    int size;
    int top;
    int *S;
};

void create_stack(struct stack *s)
{
    cout << "Enter the size of the stack " << endl;
    cin >> s->size;
    s->top = -1;
    s->S = new int[s->size];
}

void display_stack(struct stack st)
{
    for (int i = st.top; i >= 0; i--)
        cout << st.S[i] << " ";
    cout << endl;
}

void push_stack(struct stack *st, int x)
{
    if (st->top == st->size - 1)
        cout << "Stack overflow " << endl;
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop_stack(struct stack *st)
{
    int data = -1;
    if (st->top == -1)
        cout << "stack underflow " << endl;
    else
        data = st->S[st->top--];

    return data;
}

int peek_stack(struct stack st, int index)
{
    int x = 0;
    if (st.top - index + 1 < 0)
        cout << "Invalid stack index " << endl;
    else
        x = st.S[st.top - index + 1];

    return x;
}
bool isempty(struct stack st)
{
    return st.top == -1;
}
int stack_top(struct stack st)
{
    if (!isempty(st))
        return st.S[st.top];
    return -1;
}

bool isfull(struct stack st)
{
    return st.top == st.size - 1;
}



int main()
{

    struct stack st;
    create_stack(&st);
    push_stack(&st, 10);
    push_stack(&st, 20);
    push_stack(&st, 30);
    // if size is less than number of elements pushed thne for rest of the element it will show overflow
    push_stack(&st, 40);
    push_stack(&st, 50);
    display_stack(st);

    cout << "poping the first value from the stack " << pop_stack(&st) << endl;


    cout<<"peekind the value from the stack "<<peek_stack(st,3)<<endl;
  cout<<boolalpha;//use to show the boolean result true or false
    cout<<"the stack is empty "<<isempty(st)<<endl;
    cout<<"the stack is full "<<isfull(st)<<endl;
    cout<<"the top value of the stack on which it is pointing is  "<<stack_top(st);
    return 0;
}