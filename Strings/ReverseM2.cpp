#include<iostream>
using namespace std;
int main()
{
    char A[]="Python";
    char t;
    int i,j;
    for(j=0;A[j]!='\0';j++)
    {

    }
    j=j-1;
    for(i=0;i<j;i++,j--)
    {
        t=A[i];
        A[i]=A[j];
        A[j]=t;
    }
    printf("The reversed string is : %s",A);
    return 0;
}