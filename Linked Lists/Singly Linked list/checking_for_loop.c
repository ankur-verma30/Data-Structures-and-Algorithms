#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL, *second = NULL, *third = NULL;

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
// for creating the second linked list
void create2(int a[], int n)
{
    int i;
    struct node *t, *last;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = a[0];
    second->next = NULL;
    last = second;
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
int IsLoop(struct node *f)
{
    struct node *p, *q;
    p = q = first;
    do
    {
        p = p->next;
        q = q->next;
        q = q != NULL ? q->next : NULL;

    } while (p && q && p != q);
    if (p == q)
        return 1;
    else
        return 0;
}

int main()
{
    struct node *t1, *t2;
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1; // loop has been created
    if (IsLoop(first) == 1)
        printf("Loop is present in the linked list");
    else
        printf("Loop is not present in the linked list");
    return 0;
}