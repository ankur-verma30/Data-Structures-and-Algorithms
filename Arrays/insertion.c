#include<stdio.h>
struct array {
  int A[20];
  int size;
  int length;
};

void display(struct array arr)
{
  printf("Elements are \n");
    for(int i=0;i<arr.length;i++)
    printf("%d ",arr.A[i]);
    printf("\n");
    return 0;
}

void append(struct array *arr,int x)
{
  if(arr->length < arr->size)
  arr->A[arr->length++]=x;
}

void insertion(struct array *arr,int index,int x)
{
  if(index>=0 &&index <=arr->length)
for(int i=arr->length;i>index;i--)
arr->A[i]=arr->A[i-1];
arr->A[index]=x;
arr->length++;
return 0;
}



int main()
{
 struct array arr={{2,3,4,5,6},20,5};
 append(&arr,10);
display(arr);
insertion( &arr,5,10);
display(arr);
return 0;
}