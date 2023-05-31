#include<stdio.h>
struct array {
  int A[20];
  int size;
  int length;
};
int delete(struct array *arr,int index)
{
int x=0;
if(index>=0&&x<=arr->length)
{
    x=arr->A[index];
    for(int i=index;i<arr->length-1;i++)
    arr->A[i]=arr->A[i+1];
    arr->length--;
}
return x;
}
void display(struct array arr)
{
  printf("Elements are \n");
    for(int i=0;i<arr.length;i++)
    printf("%d ",arr.A[i]);
    printf("\n");
    return 0;
}
int main()
{
 struct array arr={{2,3,4,5,6},20,5};
display(arr);
printf("%d\n",delete(&arr,4));
printf("After Deletion ");
display(arr);
return 0;
}