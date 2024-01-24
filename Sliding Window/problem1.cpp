/*Given an array we have to find the maximum sum of the subarray of given size */
#include <bits/stdc++.h>

using namespace std;

long subarraySum(vector<int> &a, int k)
{
    int start = 0, end = 0;
    long sum = 0, maxi = 0;
    while (end < a.size())
    {
        if (end - start + 1 < k)
        {
            sum += a[end];
            end++;
        }
        if (end - start + 1 == k)
        {
            sum += a[end];
            maxi = max(maxi, sum);
            sum = sum - a[start];
            start++;
            end++;
        }
    }
    return maxi;
}

int main()
{
    int a, k;
    vector<int> nums;
    int size = 0;
    cout << "Enter the size of the array" << endl;
    cin >> size;
    cout << "Enter number of elements ";
    for (int i = 0; i < size; i++)
    {
        cin >> a;
        nums.push_back(a);
    }
    cout << "Enter the size of the subarray " << endl;
    cin >> k;

    long result = subarraySum(nums, k);
    cout << "the maximum value  of the subarray is " << result << endl;

    return 0;
}