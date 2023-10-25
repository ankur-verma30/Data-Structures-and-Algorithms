// quick sort algorithm

#include <bits/stdc++.h>

using namespace std;

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int partition(vector<int> &a, int low, int high)
{
    int pivot = a[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (a[i] <= pivot && i <= high - 1)
            i++;

        while (a[j] > pivot && j >= low + 1)
            j--;

        if (i < j)
            swap(a[i], a[j]);
    }

    swap(a[low],a[j]);
    return j;
}

void  quickSort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(a, low, high);
        quickSort(a, low, partitionIndex - 1);
        quickSort(a, partitionIndex + 1, high);
    }
    
}

int main()
{
     vector<int> arr{1, 2, 5, 4, 3, 8, 45, 745, 37, 5, 34, 5, 34, 36, 634, 634, 34, 6, 34, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);

    for (auto it : arr)
        cout << it << " ";
    cout << endl;

    return 0;
}