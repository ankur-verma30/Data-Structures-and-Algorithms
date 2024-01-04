#include <stdio.h>

void InsertInHeap(int A[], int n)
{

    int i = n, temp;
    temp = A[i];

    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

int deleteFromTheHeap(int A[], int n) // we can only delete the max element in the heap
{
    int i, j, x, temp;
    int val = A[1]; // we take the first value of the heap in the val
    x = A[n];       // put the last value of the heap as we have to put the deleted value in the last
    A[1] = A[n];    // copied the last value in the first position of the heap
    A[n] = val;     // pasted last value in the heap i.e. the deleted value
    i = 1;          // started the iteration from the first position it is 1 based index array
    j = i * 2;      // j is pointing at the left child of the value of i

    while (j < n - 1) // started loop max value is at the root
    {
        if (A[j + 1] > A[j]) // after deletion both the childerns where compared if the left child is greater we will do nothing but if the right child is greater we will move the j to 1 place ahead
        {
            j = j + 1;
        }
        if (A[j] > A[i]) // then compare the right child with the root element if the root is greater than we will swap the right child and the root element otherwise we will do nothing
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp; // swapping is done
            i = j;       // the position of the root is copied to the i index
            j = j * 2;   // the value of the j is mutiplied to get the child of that index
        }
        else // if the root is already greater than the right child then it already better then we should do nothing and break the loop and return the deleted value[[]]
            break;
    }
    return val;
}
int main()
{

    int A[] = {0, 10, 20, 30, 25, 5, 40, 35};
    // 40,25,35,10,5,20,30
    for (int i = 2; i <= 7; i++)
    {
        InsertInHeap(A, i);
    }

    for (int i = 1; i < sizeof(A) / sizeof(A[0]); i++)
        printf("%d\t", A[i]);

    printf("\n");

    // printf("Deleted value: %d\n", deleteFromTheHeap(A, 7));

    for (int i = 1; i < sizeof(A) / sizeof(A[0]); i++)
        printf("%d\t", A[i]);
    printf("\n");

    for (int i = 7; i > 1; i--)
    {
        deleteFromTheHeap(A, i);
    }

    for (int i = 1; i < sizeof(A) / sizeof(A[0]); i++)
        printf("%d\t", A[i]); // the value get sorted in the ascending order

    return 0;
}