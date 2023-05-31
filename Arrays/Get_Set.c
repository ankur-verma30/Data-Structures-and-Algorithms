#include<stdio.h>
#include<stdlib.h>
struct array{
int *A;
int size;
int length;
};
 int GetIndex(struct array arr,int index)
{
    if(index>=0&&index<arr.length)
    return arr.A[index];
    return -1;
}
int SetIndex(struct array *arr, int index,int x)
{
    if(index>=0&&index<arr->length)
    arr->A[index]=x;
    return arr->A[index];
}
int Maximum(struct array arr)
{
    int max=0;
    max=arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]>max)
        max=arr.A[i];
    }
    return max;
}
int Minimum(struct array arr)
{
    int min=0;
    min=arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]<min)
        min=arr.A[i];
    }
    return min;
}
int SumAndAverage(struct array arr)
{
    int Total=0;
    for(int i=0;i<arr.length;i++)
    Total+=arr.A[i];
    printf("The total of the given array is %d \n",Total);
    return Total/arr.length;
}
int main()
{
    struct array arr;
    int n=0,index=0,x=0;
    printf("Enter the size of the array\n");
    scanf("%d",&arr.size);
    arr.A=(int*)malloc(arr.size*sizeof(int));
    arr.length=0;
    printf("Enter the number of elements \n");
    scanf("%d",&n);
    printf("Enter all elements\n");
    for(int i=0;i<n;i++)
    scanf("%d",&arr.A[i]);
    arr.length=n;
    printf("Input the index value\n");
    scanf("%d",&index);
    printf("The Value is %d\n ",GetIndex(arr,index));
    printf("Enter element to set value\n");
    scanf("%d",&x);
    printf("The set value is %d \n",SetIndex(&arr,index,x));
    printf("The maximum value in the array is %d\n ",Maximum(arr));
    printf("The minimum value in the array is %d \n ",Minimum(arr));
    printf("The average value is %d",SumAndAverage(arr));
    return 0;
}