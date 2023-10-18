// swap the array using recursion
#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
// reversing the array using recursion using two pointers
void reverse(int arr[], int l, int r)
{
    if (l >= r)
        return;
    swap(arr[l], arr[r]);
    reverse(arr, l + 1, r - 1);
}

// reverse the array using single variable
void reverse2(int arr[], int n, int i)
{
    if (i >= n / 2)
        return;
    swap(arr[i], arr[n - i - 1]);
    reverse2(arr, n, i + 1);
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 6, 7};
    int size = sizeof(arr) / sizeof(int);
    reverse(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;

    int arr2[] = {12, 13, 14, 15, 16, 17};
    int n = sizeof(arr2) / sizeof(int);
    reverse2(arr2, n, 0);
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";
        

        return 0;
}