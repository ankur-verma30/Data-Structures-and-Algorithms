#include <iostream>
#include <stdio.h>
#include <stdlib.h>
// Not Completed come to it later
class Array
{
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array()
    {
        delete[] A;
    }
    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int Get(int index);
    int set(int index, int x);
    int Max();
    int Min();
    int Sum();
    int Avg();
    void Reverse();
    void InsertSort(int x);
    int isSorted9();
    void Rearrange();
    Array *Merge(Array arr2);
    Array *Union(Array *arr2);
    Array *Intersection(Array *arr2);
    Array *Difference(Array *arr2);
};
void Array::Display()
{
    int i;
    printf("\nElements are \n");
    for (i = 0; i < length; i++)
        printf("%d ", A[i]);
}
void Array::Append(int x)
{
    if (length < size)
        A[length++] = x;
}
void Array::Insert(int index, int x)
{
    int i = 0;
    if (index >= 0 && index <= length)
    {
        for (i = length; i > index; i--)
            A[i] = A[i - 1];
        A[index] = x;
        length++;
    }
}
int Array::LinearSearch(int key)
{
}
int Array::BinarySearch(int key)
{
}
int Array::Get(int index)
{
}
int Array::set(int index, int x)
{
}
int Array::Max()
{
}
int Array::Min()
{
}
int Array::Sum()
{
}
int Array::Avg()
{
}
void Array::Reverse()
{
}
void Array::InsertSort(int x)
{
}
int Array::isSorted9()
{
}
void Array::Rearrange()
{
    int i, j;
    i = 0;
    j = length - 1;
    while (i < j)
    {
        while (A[i] < 0)
            i++;
        while (A[j] >= 0)
            j--;
        if (i < j)
            swap(&A[i], &A[j]);
    }
}
Array *Merge(Array arr2)
{
    int i, j, k;
    i = j = k = 0;
    // // Array *arr3=new Array(length+arr2.length);
    // // while(i<length && j<arr2.length)
    // {
    //     if(A[i]<arr2.A[j])
    //     arr3
    // }
}
Array Array::*Union(Array *arr2)
{
}
Array Array::*Intersection(Array *arr2)
{
}
Array Array::*Difference(Array *arr2)
{
}