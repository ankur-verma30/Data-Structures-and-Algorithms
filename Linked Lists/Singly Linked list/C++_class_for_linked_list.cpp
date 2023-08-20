#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class linkedlist
{
private:
    node *first;

public:
    linkedlist()
    {
        first = NULL;
    }
    linkedlist(int A[], int n);
    ~linkedlist();
    void display();
    void insert(int index, int x);
    int deletion(int index);
    int length();
};
linkedlist::linkedlist(int A[], int n)
{
    node *last, *t;
    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
linkedlist::~linkedlist()
{
    node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void linkedlist::display()
{
    node *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
int linkedlist::length()
{
    node *p = first;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}
void linkedlist::insert(int index, int x)
{
    node *t, *p = first;
    if (index < 0 || index > length())
        return;
    t = new node;
    t->data = x;
    t->next = NULL;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}
int linkedlist::deletion(int index)
{
    int x = -1;
    node *p, *q = NULL;
    if (index < 1 || index > length())
        return -1;
    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = first;
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

int main()
{
    int A[] = {1, 2, 3, 45, 6};
    linkedlist l(A, 5);
    l.insert(0, 10);
    l.display();
    cout << "the lenght of the linked list : " << l.length() << endl;

    return 0;
}