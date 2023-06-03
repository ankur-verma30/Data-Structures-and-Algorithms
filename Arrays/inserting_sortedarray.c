#include <stdio.h>
#include <stdbool.h>
struct array
{
    int *A;
    int size;
    int length;
};
void swap(int *x, int *y)
{
    int temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
}
void InsertSort(struct array *arr, int x) // inserting element in a sorted array
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
        return;
    while (x < arr->A[i] && i >= 0)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}
void display(struct array arr)
{
    printf("\nElement are\n");
    for (int i = 0; i < arr.length; i++)
        printf("%d  ", arr.A[i]);
    return 0;
}
bool isSorted(struct array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return false;
        else
            return true;
    }
}
void Rearrange(struct array *arr)
{
    int i = 0, j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}
int main()
{
    struct array arr;
    int n = 0, x = 0;
    printf("Enter the size of the array\n");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;
    printf("Enter the Lenght \n");
    scanf("%d", &n);
    printf("Enter all elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr.A[i]);
    arr.length = n;
    Rearrange(&arr);
    // printf("Enter the element want to insert\n");
    // scanf("%d",&x);
    // InsertSort(&arr, x);
    // printf("Array is sorted - %s\n ",isSorted(arr)?"true":"false");//how to express boolean values
    display(arr);
    return 0;
}