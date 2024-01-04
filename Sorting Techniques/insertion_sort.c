/*
In insertion sort we assume that first element is sorted and then check all the elements and move to the side of the sorted list

Time complexity by this sorting is O(n^2)
Insertion sort is more compatiable with the linked list as shifting of elements is not required
*/
#include<stdio.h>



void InsetionSort(int A[],int n){
    int i,j,x;
    for(int i=1;i<n;i++){
        j=i-1;
        x=A[i];
        while(j>-1 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

int main(){

    int A[]={2,4,5,3,7,8,9,7,5,6,9,10,11,2,1};
    int n=sizeof(A)/sizeof(A[0]);

    InsetionSort(A,n);

    for(int i=0;i<n;i++ )
    printf("%d  ",A[i]);

    return 0;
}