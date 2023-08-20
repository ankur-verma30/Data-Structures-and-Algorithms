#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first = NULL;

void Insert_last(struct node *p, int x)
{
    struct node *last, *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
        first = last = NULL;
    else
    {
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
int main()
{
    Insert_last(first, 8);
    display(first);
    Insert_last(first, 16);
    display(first);
    return 0;
}