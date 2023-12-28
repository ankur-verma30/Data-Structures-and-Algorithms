#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    struct Node *rchild;
    int data;
} *root = NULL;

void InsertInBinaryTree(int key)
{
    struct Node *t = root;
    struct Node *r = NULL, *p;

    if (root == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

void InorderTraversal(struct Node *p)
{
    if (p)
    {
        InorderTraversal(p->lchild);
        printf("%d ", p->data);
        InorderTraversal(p->rchild);
    }
}

struct Node *SearchInBinaryTree(int key)
{
    struct Node *t = root;
    while (t != NULL)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

struct Node *RecursiveInsertInBinaryTree(struct Node *p, int key)
{
    struct Node *t = NULL;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = RecursiveInsertInBinaryTree(p->lchild, key);
    else if (key > p->data)
        p->rchild = RecursiveInsertInBinaryTree(p->rchild, key);

    return p;
}
int HeightOfBST(struct Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = HeightOfBST(p->lchild);
    y = HeightOfBST(p->rchild);
    return x > y ? x + 1 : y + 1;
}

struct Node *InorderPredecessor(struct Node *p)
{
    while (p && p->rchild != NULL)
        p = p->rchild;

    return p;
}

struct Node *InorderSuccecessor(struct Node *p)
{
    while (p && p->lchild != NULL)
        p = p->lchild;

    return p;
}

struct Node *DeletionInBinarySearchTree(struct Node *p, int key)
{

    if (p == NULL)
        return NULL;
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
        {
            root = NULL;

            free(p);
            return NULL;
        }
    }

    struct Node *q = NULL;

    if (key < p->data)
        p->lchild = DeletionInBinarySearchTree(p->lchild, key);
    else if (key > p->data)
        p->rchild = DeletionInBinarySearchTree(p->rchild, key);
    else
    {
        if (HeightOfBST(p->lchild) > HeightOfBST(p->rchild))
        {
            q = InorderPredecessor(p->lchild);
            p->data = q->data;
            p->lchild = DeletionInBinarySearchTree(p->lchild, q->data);
        }
        else
        {
            q = InorderSuccecessor(p->rchild);
            p->data = q->data;
            p->rchild = DeletionInBinarySearchTree(p->rchild, q->data);
        }
    }
    return p;
}
int main()
{

    struct Node *temp;
    // InsertInBinaryTree(10);
    // InsertInBinaryTree(20);
    // InsertInBinaryTree(70);
    // InsertInBinaryTree(30);
    // InsertInBinaryTree(50);
    // InsertInBinaryTree(60);
    root = RecursiveInsertInBinaryTree(root, 10);
    RecursiveInsertInBinaryTree(root, 20);
    RecursiveInsertInBinaryTree(root, 30);
    RecursiveInsertInBinaryTree(root, 40);
    RecursiveInsertInBinaryTree(root, 50);

    DeletionInBinarySearchTree(root, 90);

    printf("The inorder traversal after insertion of the elements is \n");
    InorderTraversal(root);
    printf("\n");

    temp = SearchInBinaryTree(20);
    if (temp != NULL)
        printf("Element is found in the Binaray tree %d ", temp->data);
    else
        printf("No element found in the Binaray tree");

    return 0;
}