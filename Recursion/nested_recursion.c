#include<stdio.h>
int fun(int n)
{
    if(n>100)
    return n-10;
    return fun(fun(n+11));
}
int main()
{
    int r=0;
    r=fun(30);
    printf("The value is = %d\n",r);
    return 0;
}