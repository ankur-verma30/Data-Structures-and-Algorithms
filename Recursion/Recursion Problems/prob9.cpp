// printing subsequences whose sum is k
#include <bits/stdc++.h>

using namespace std;

void print(int index, vector<int> &ds, int arr[], int n, int sum, int s)
{
    if (index == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }
    ds.push_back(arr[index]);
    s += arr[index];
    print(index + 1, ds, arr, n, sum, s);
    ds.pop_back();
    s -= arr[index];
    print(index + 1, ds, arr, n, sum, s);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 10};
    int n = 11;
    vector<int> ds;
    int sum = 10;
    print(0, ds, arr, 11, sum, 0);
    return 0;
}