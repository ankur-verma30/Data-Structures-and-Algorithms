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
int recursive_count(struct node *p)
{
    if (p == 0)
        return 0;
    else
        return 1 + recursive_count(p->next);
}
int add(struct node *p)
{
    int sum = 0;
    while (p != 0)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}
int recursive_add(struct node *p)
{
    if (p == 0)
        return 0;
    else
        return recursive_add(p->next) + p->data;
}

int main()
{
    int a[] = {3, 5, 7, 9, 11};
    create(a, 5);
    printf("the number of elements in linked list is = %d\n", count(first));
    printf("The recursive way to find total number of element= %d\n", recursive_count(first));
    printf("Add the elements of the linked list= %d\n", add(first));
    printf("Recursive add of the linked list elements= %d\n", recursive_add(first));
    return 0;
}