#include<stdio.h>

struct array {
  int *A;
  int size;
  int length;
};
//using iteration 
int binarySrch(struct array arr,int l,int h,int key)
{
    int mid=(l+h)/2;
while(l<=h)
{
    if(key==arr.A[mid])
    return mid;
    if(key<arr.A[mid])
    h=mid-1;
    else
    l=mid+1;
}
return -1;
}
//METHOD 2- Using Recurssion 
int BNRYSRCH(struct array arr,int l,int h, int key)
{
    int  mid=(l+h)/2;
    if(l<=h)
    {
        if(key==arr.A[mid])
        return mid;
        if(key<arr.A[mid])
        return BNRYSRCH(arr,l,mid-1,key);
        else
        return BNRYSRCH(arr,mid+1,h,key);

    }
    return -1;
}
int main()
{
    struct array arr;
    int l=0;int h;
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
    h=arr.length;
    printf("Enter the element you want to search\n");
    scanf("%d",&x);
    printf("The seached position is %d and %d ", binarySrch(arr,l,h,x), BNRYSRCH(arr,l,h,x));
    return 0;
}