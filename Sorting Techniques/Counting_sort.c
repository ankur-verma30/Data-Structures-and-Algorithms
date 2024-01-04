#include <stdio.h>
#include<stdlib.h>

int Maximum(int A[], int n)
{
    int Maxi =__WINT_MIN__;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > Maxi)
            Maxi = A[i];
    }
    return Maxi;
}

void CountingSort(int A[], int n)
{
    int *C, len=1;
    len += Maximum(A, n);
    C = (int *)malloc(sizeof(int) * (len + 1));

    for (int i = 0; i < len; i++)
        C[i] = 0;

    for (int i = 0; i < n; i++)
        C[A[i]]++;

    int i = 0, j = 0;
    while (i < len )
    {
        if (C[i] > 0)
        {
            A[j++] = i;
            C[i]--;
        }
        else
            i++;
    }
}

int main()
{
    int A[] = {11, 1, 3, 13, 7, 3, 2, 6, 9, 4, 5, 10, 3};
    int n = sizeof(A) / sizeof(A[0]);

    CountingSort(A, n);

    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}