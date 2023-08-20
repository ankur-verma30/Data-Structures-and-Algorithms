#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
} *head;
void CreateNode(int A[], int n)
{
    struct node *t, *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = A[0];
    head->next = head;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
    printf("linked list is created\n");
}
void DisplayNode(struct node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != head);
    printf("\n");
}
// Recursive method to display the linked list
void RecursiveDisplay(struct node *h)
{
    static int flag = 0;
    if ((flag == 0) || (h != head))
    {
        flag = 1;
        printf("%d ", h->data);
        RecursiveDisplay(h->next);
    }
    flag = 0;
}

// function for the length of the linked list
int LengthOfNode(struct node *p)
{
    int length = 0;
    do
    {
        length++;
        p = p->next;
    } while (p != head);
    return length;
}

// function for the insertion of a node
void InsetNode(struct node *p, int index, int x)
{
    struct node *t;
    int i;
    if (index == 0)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
                p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}
// function for deletingn the node
int DeleteNode(struct node *p, int position)
{
    struct node *q;
    int i, x;
    if (position < 0 || position > LengthOfNode(head)){
        return -1;
    }
    if (position == 1)
    {
        while (p->next != head)
            p = p->next;
        x = head->data;
        if (head == p)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for (i = 0; i < position - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return 0;
}

int main()
{
    int A[] = {2, 3, 4, 5, 6};

    CreateNode(A, 5);
    RecursiveDisplay(head);
    printf("\n");
    InsetNode(head, 0, 10);
    DisplayNode(head);
    printf("After Deletion of the node\n");
    DeleteNode(head,3);
    DisplayNode(head);

    return 0;
}