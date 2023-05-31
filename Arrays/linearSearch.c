#include<stdio.h>
#include<stdlib.h>
struct array {
  int *A;
  int size;
  int length;
};
//applying methods to improve the search 
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int LinearSearch(struct array *arr,int key)
{

for(int i=0;i<arr->length;i++) 
{
if(key==arr->A[i])
swap(&arr->A[i],&arr->A[i-1]);//this is call transportation
// swap(&arr->A[i],&arr->A[0]);//this is called move to head method
return i+1;
}
return -1;
}
/*
int LinearSearch(struct array arr,int key)
{
    for(int i=0;i<arr.length;i++)
    {
        if(key==arr.A[i])
        return i+1;
    }
    return -1;
}*/
int main()
{
    struct array arr;
    int n=0,x=0;
    printf("Enter the size of the array\n");
    scanf("%d",&arr.size);
    arr.A=(int*)malloc(arr.size*sizeof(int));
    arr.length=0;
    printf("Enter the numbers \n");
    scanf("%d",&n);
    printf("Enter all elements\n");
    for(int i=0;i<n;i++)
    scanf("%d",&arr.A[i]);
    arr.length=n;
    printf("Enter the element you want to search\n");
    scanf("%d",&x);
    printf("The position of searched element is %d ",LinearSearch( &arr,x) );
    return 0;
}