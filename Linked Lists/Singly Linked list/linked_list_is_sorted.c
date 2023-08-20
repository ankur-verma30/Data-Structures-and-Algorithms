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
int isSorted(struct node *p){
    int x=INT_MIN;
    while(p!=NULL)
    {
        if(p->data<x)
        return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}
int main()
{
    int a[] = {1, 3, 5, 7, 9};
    create(a, 5);
    display(first);
    printf("\n");
   if(isSorted(first))
   printf("The linked list is sorted.\n");
   else
   {
    printf("The list is not sorted.\n");
   }
   printf("%d\n",INT_MIN);
    return 0;
}