#include <stdio.h>
#define Size 10

int hash(int key)
{
    return key % Size;
}

int probe(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while (H[(index + i) % Size] != 0)
        i++;
    return (index + i) % Size;
}

void insert(int H[], int key)
{
    int index = hash(key);
    if (H[index] != 0)
        index = probe(H, key);
    H[index] = key;
}

int search(int H[], int key)
{
    int index = hash(key);
    int i = 0;
    while (H[(index + 1) % Size] != key)
        i++;
    return (index + i) % Size;
}

int main()
{

    int HT[10] = {0};
    insert(HT, 12);
    insert(HT, 13);
    insert(HT, 14);
    insert(HT, 15);
    insert(HT, 16);

    printf("key found at index %d\n", search(HT, 16));
    int n=sizeof(HT)/sizeof(HT[0]);

    for(int i=0;i<n;i++)
    printf("%d ",HT[i]);
    
    printf("completed the program");

    return 0;
}