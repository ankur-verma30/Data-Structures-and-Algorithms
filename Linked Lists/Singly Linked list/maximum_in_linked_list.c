#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
int maximum(struct node *p)
{
    int max = INT_MIN;
    // this is for the minimum number present in the signed integer
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}
int recursive_maximum(struct node *p)
{
    int x = 0;

    if (p == 0)
        return INT_MIN;
    x = recursive_maximum(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}
int recursive_max(struct node *p)
{
    int x = 0;

    if (p == 0)
        return INT_MIN;
    else
        x = recursive_max(p->next);
    return (x > p->data) ? x : p->data;
}
int main()
{
    int a[] = {3, 2, 5, 7, 85, 440, 56, 7, 4, 3, 2, 56, 56, 88, 1};
    create(a, 15);
    printf(" the maximum among them is = %d\n", maximum(first));
    printf(" the maximum among them is = %d\n", recursive_maximum(first));
    printf(" the maximum among them is = %d", recursive_max(first));
    return 0;
}