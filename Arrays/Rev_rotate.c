c#include <stdio.h>
#include <stdlib.h>
struct array
{
    int *A;
    int size;
    int length;
};

void reverse(struct array *arr)
{
    int *B;
    int i, j;
    B = (int *)malloc(arr->length * sizeof(int));
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}
void reverse2(struct array *arr)
{
    int i, j, temp = 0;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}
void display(struct array arr)
{
    printf("Reversed Elements are\n");
    for (int i = 0; i < arr.length; i++)
        printf("%d  ", arr.A[i]);
}
int main(int argc, char const *argv[])
{
    struct array arr;
    int n = 0;
    printf("Enter the size of the array\n");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;
    printf("Enter the number of elements \n");
    scanf("%d", &n);
    printf("Enter all elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr.A[i]);
    arr.length = n;
    reverse2(&arr);
    display(arr);
    return 0;
}
