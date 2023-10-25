// count the number of subsequences that satisfies the condition
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int printSubsequence(int index, vector<int> ds, int arr[], int s, int sum, int n)
{
    if (index == n)
    {
        if (s == sum)
            return 1;
        else
            return 0;
    }
    ds.push_back(arr[index]);
    s += arr[index];

    int l = printSubsequence(index + 1, ds, arr, s, sum, n);
    s -= arr[index];
    ds.pop_back();

    int r = printSubsequence(index + 1, ds, arr, s, sum, n);
    return l + r;
}
int main()
{
    int arr[]{1, 2, 3, 3};
    int n = 4;
    int sum = 3;
    vector<int> ds;
    int count = printSubsequence(0, ds, arr, 0, sum, n);
    cout << "count is : " << count << endl;

    return 0;
}