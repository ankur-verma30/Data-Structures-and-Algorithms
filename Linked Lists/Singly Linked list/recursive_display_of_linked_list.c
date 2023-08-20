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
void recursive_display(struct node *p)
{
    if (p != NULL)
    {
        printf("%d\t", p->data);
        recursive_display(p->next);
    }
}
void reverse_recursive_display(struct node *p)
{
    if (p != NULL)
    {
        reverse_recursive_display(p->next);
        printf("%d\t", p->data);
    }
}
int main()
{
    int a[] = {3, 5, 7, 9, 11};
    create(a, 5);
    recursive_display(first);
    printf("\n");
    reverse_recursive_display(first);
    return 0;
}