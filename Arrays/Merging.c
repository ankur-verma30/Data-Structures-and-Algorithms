#include<stdio.h>
#include<stdlib.h>
struct array{
int *A;
int size;
int length;
};

struct array * merge(struct array *arr1,struct array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct array *arr3=(struct array *)malloc(sizeof(struct array));
    while(i<arr1->length&&j<arr2->length)
    {
    if(arr1->A[i]<arr2->A[j])
    arr3->A[k++]=arr1->A[i++];
    else
     arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++)
    arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
    arr3->A[k++]=arr2->A[j];
    arr3->length=arr1->length+arr2->length;
    arr3->size=arr1->size+arr2->size;
}
void  display(struct array arr1)
{
    printf("\nElement are\n");
    for(int i=0;i<arr1.length;i++)
    printf("%d  ",arr1.A[i]);
    return 0;
}
int main()
{
    struct array arr1,arr2;
    struct array *arr3;
    int n=0,m=0;
    printf("Enter the size of the array1\n");
    scanf("%d",&arr1.size);
    printf("Enter the size of the array2\n");
    scanf("%d",&arr2.size);
    arr1.A=(int*)malloc(arr1.size*sizeof(int));
    arr2.A=(int*)malloc(arr2.size*sizeof(int));
    arr1.length=0;
    arr2.length=0;
    printf("Enter the no. of element for 1st array  \n");
    scanf("%d",&n);
    printf("Enter the no. of element for 2st array  \n");
    scanf("%d",&m);
    printf("Enter all elements for 1st array\n");
    for(int i=0;i<n;i++)
    scanf("%d",&arr1.A[i]); 
    printf("Enter all elements for 2nd array\n");
    for(int i=0;i<m;i++)
    scanf("%d",&arr2.A[i]);
    arr1.length=n;
    arr2.length=m;
    display(arr1);
    display(arr2);
    arr3=merge(&arr1,&arr2);
    printf("\nArray after merging");
    display(*arr3);
    return 0;
}
