#include<stdio.h>
void fun(int n)
{
    if(n>0)
    {
        printf("%d\n",n);
        fun(n-1);
        fun(n-1);
       
    }

}
int main()
{
    int n=0;
    printf("Input the values");
    scanf("%d",&n);
    fun(n);
    return 0;

}