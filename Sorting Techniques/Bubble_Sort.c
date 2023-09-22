// there are n number of elements there are n-1 passes
// No of comparisons for n elements will be sum of n natural numbers till n-1
// Maximum number of swaps will be (n*(n-1))/2 --O(n^2)
//  Time complexity is O(n^2)


// why it is called bubble sort??--- as we throw the stone in water the heavier thing i.e stone settles down into water whereas the bubbles rise up just like that here the heaviest element or largest element settle downn and lighter element or smaller element rises up


// In pass 1 we got 1 greatest element in 2 passes we get 2 greatest elements so same goes for k passes we get k greatest elements

#include <stdio.h>

void swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
            }
        }
    }
}
int main()
{
    int A[100], n = 0;
    printf("Enter the number of elements ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    BubbleSort(A, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}
