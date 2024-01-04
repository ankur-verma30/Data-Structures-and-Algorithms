#include <stdio.h>

void ShellSort(int A[], int n)
{
    for (int gap = n / 2; gap >= 1; gap /= 2)
    {
        for (int j = gap; j < n; j++)
        {
            int temp = A[j];
            int i = j - gap;
            while (i >= 0 && A[i] > temp)
            {
                A[i + gap] = A[i];
                i = i - gap;
            }
            A[i + gap] = temp;
        }
    }
}

int main()
{
    int A[] = {11, 1, 3, 13, 7, 3, 2, 6, 9, 4, 5, 10, 3};
    int n = sizeof(A) / sizeof(A[0]);

    ShellSort(A, n);

    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
}