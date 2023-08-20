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
struct node *search_node(struct node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}
struct node *recursive_search_node(struct node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return recursive_search_node(p->next, key);
}
struct node *modified_search_node(struct node *p, int key)
{
    struct node *q;

    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
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
    struct node *temp;
    int a[] = {3, 5, 7, 9, 11};
    create(a, 5);
    temp = search_node(first, 31);
    if (temp)
        printf("KEY is found   = %d\n", temp->data);
    else
        printf("KEY is not found\n");
    printf("---------RECURSIVE CALL------------------\n");
    temp = recursive_search_node(first, 31);
    if (temp)
        printf("KEY is found   = %d\n", temp->data);
    else
        printf("KEY is not found\n");
    printf("---------MODIFIED LINEAR SEARCH------------------\n");
    temp = modified_search_node(first, 11);
    if (temp)
        printf("KEY is found   = %d\n", temp->data);
    else
        printf("KEY is not found\n");
    display(first);
    // 11 is brought at the first place

    return 0;
}