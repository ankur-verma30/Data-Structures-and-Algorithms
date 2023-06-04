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
        printf("\n");
}

void insert(struct node *p, int pos, int x)
{
    if (pos < 0) // there should be length checking also using the count function
        return;
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    if (pos == 0)
    {
        t->next = first;
        first = t;
    }
    else 
    {
        p = first;
        for (int i = 0; i < pos - 1 && p; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
     
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    create(a, 9);
    insert(first, 4, 10);
    display(first);
    insert(first, 3,33);
    display(first);
    return 0;
}