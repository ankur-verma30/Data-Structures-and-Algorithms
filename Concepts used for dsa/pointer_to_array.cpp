#include<iostream>
using namespace std;
void fun1(int a[ ])
{
int z=(sizeof(a)/sizeof(int));
cout<<endl<<"z is ="<<z;
}
int *fun2(int n)
{
    int *p;
    p=(int *)malloc(n*sizeof(int));//used in c to create malloc
    //other method of creating malloc is p=new int[n]; used in c++
    for(int i=0;i<n;i++)
    p[i]=2*i;
    return (p);
}
int main()
{
    int a[ ]={2,4,6,8,10};
    int *A;
    int n=5;
    for(int x:a)
    cout<<x<<" ";
    int y=(sizeof(a)/sizeof(int));
    cout<<endl<<"Size is ="<<y;//in this we get array size is as 5 that we have expected 
    fun1(a);
    cout<<endl;//but here in this function we get size as 2 why so because it gives the value of the pointer to array
    A=fun2(n);//dynamic allocation of the array in the heap memory
    for(int i=0;i<n;i++)
    cout<<A[i]<< " ";
    return 0;
}