#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *first = NULL;

// Creation of the nodes
void CreateNode(int A[], int n)
{
    struct node *t, *last;
    int i;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}
// display of the nodes
void DisplayNode(struct node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
// length of the linked list
int LengthOfList(struct node *p)
{
    int length = 0;
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}

// Inserting new node in the list
void InsertNode(struct node *p, int index, int x)
{
    struct node *t;
    int i;
    if (index < 0 || index > LengthOfList(first))
        return;
    if (index == 0)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}
// deletion of the node from the linked list
int DeleteNode(struct node *p, int index)
{
    
    int x = -1;
    if (index < 1 || index > LengthOfList(first))
        return -1;
    if (index == 1)
    {
        first = first->next;
        if (first)
            first->prev = NULL;
        x = p->data;
        free(p);
    }
    else{
        for(int i=0;i<index-1;i++)
        p=p->next;
        p->prev->next =p->next;
        if(p->next)
        p->next->prev = p->prev;
        x=p->data;
        free(p);
    }
    return x;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    CreateNode(A, 5);
    DisplayNode(first);
    printf("The length of the linked list is: %d\n", LengthOfList(first));
    InsertNode(first, 3, 13);
    DisplayNode(first);
    printf("The length of the linked list is: %d\n", LengthOfList(first));
    printf("%d\n", DeleteNode(first,4));
    DisplayNode(first);
    printf("the length of the linked list is: %d\n", LengthOfList(first));

    return 0;
}