#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL;

void create(int a[], int n)
{
    int i;
    struct node *t, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
}
int count(struct node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}
void ReverseUsingArray(struct node *p)
{
    int *A;
    A = (int *)malloc(sizeof(int) * count(p));
    struct node *q = p;
    int i = 0;
    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}
void ReverseUsingSlidingPointer(struct node *p)
{
    struct node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
void RecursiveReverse(struct node *q, struct node *p)
{
    if (p)
    {
        RecursiveReverse(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    // ReverseUsingArray(first);
    // ReverseUsingSlidingPointer(first);
    RecursiveReverse(NULL, first);
    display(first);
    printf("\n\n");
}