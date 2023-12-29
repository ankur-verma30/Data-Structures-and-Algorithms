#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int height;
    struct Node *lchild;
    struct Node *rchild;
} *root = NULL;

int NodeHeight(struct Node *p)
{
    int height1 = 0, height2 = 0;
    height1 = p && p->lchild ? p->lchild->height : 0;
    height2 = p && p->rchild ? p->rchild->height : 0;

    return (height1 > height2) ? height1 + 1 : height2 + 1;
}

int balanceFactorOfNode(struct Node *p)
{
    int height1 = 0, height2 = 0;
    height1 = p && p->lchild ? p->lchild->height : 0;
    height2 = p && p->rchild ? p->rchild->height : 0;
    return height1 - height2;
}

struct Node *LLRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (p == root)
        root = pl;

    return pl;
}

struct Node *LRRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    plr->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if (root == p)
        root = plr;

    return plr;
}

struct Node *RRRotation(struct Node *p)
{
    return NULL;
}

struct Node *RLRotation(struct Node *p)
{
    return NULL;
}

struct Node *RecursiveInsertInAVLTree(struct Node *p, int key)
{
    struct Node *t = NULL;
    if (p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
        p->lchild = RecursiveInsertInAVLTree(p->lchild, key);
    else if (key > p->data)
        p->rchild = RecursiveInsertInAVLTree(p->rchild, key);

    p->height = NodeHeight(p);
    // balance factor of node p

    if (balanceFactorOfNode(p) == 2 && balanceFactorOfNode(p->lchild) == 1) // this should be ll rotation
        return LLRotation(p);
    else if (balanceFactorOfNode(p) == 2 && balanceFactorOfNode(p->rchild) == -1) // this should be lR rotation
        return LRRotation(p);
    else if (balanceFactorOfNode(p) == -2 && balanceFactorOfNode(p->rchild) == -1) // this should be
        return RRRotation(p);
    else if (balanceFactorOfNode(p) == -2 && balanceFactorOfNode(p->rchild) == 1)
        return RLRotation(p);

    return p;
}

int main()
{
    root = RecursiveInsertInAVLTree(root, 10);
    RecursiveInsertInAVLTree(root, 5);
    RecursiveInsertInAVLTree(root, 2);

    return 0;
}