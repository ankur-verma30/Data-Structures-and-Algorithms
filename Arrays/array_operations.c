#include <stdio.h>
#include <stdlib.h>
struct array
{
    int *A;
    int size;
    int length;
};
void display(struct array arr)
{
    printf("\nElement are\n");
    for (int i = 0; i < arr.length; i++)
        printf("%d  ", arr.A[i]);
    return 0;
}
int main()
{
    struct array arr;
    int n = 0;
    printf("Enter the size of the array\n");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;
    printf("Enter the numbers \n");
    scanf("%d", &n);
    printf("Enter all elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    arr.length = n;
    display(arr);
    return 0;
}
