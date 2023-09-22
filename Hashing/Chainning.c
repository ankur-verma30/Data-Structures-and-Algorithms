#include <stdio.h>
#include "Chains.h"

int hash(int key)
{
    return key % 10;
}

void InsertInHashTable(struct node *H[], int key)
{
    int index = hash(key);
    Sorted_Insert(&H[index], key);
}
int main()
{

    struct node *HT[10];
    struct node *tmp;
    int i;
    for (i = 0; i < 10; i++)
        HT[i] = NULL;
    int key;

    InsertInHashTable(HT, 12);
    InsertInHashTable(HT, 13);
    InsertInHashTable(HT, 14);
    InsertInHashTable(HT, 15);
    InsertInHashTable(HT, 16);

    printf("Enter the value of the key for seaching\n");
    scanf("%d", &key);

    tmp = search(HT[hash(key)], key);

    printf("The seeached key value is: %d\n", tmp->data);

    return 0;
}