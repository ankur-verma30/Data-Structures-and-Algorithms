/*Maximum of all subarray of size k*/
#include <bits/stdc++.h>

using namespace std;

vector<int> MinimumSubArray(vector<int> &nums, int k)
{

    vector<int> result;
    int maxi = 0;
    for (int i = 0; i < k; i++)
    {
        maxi = max(maxi, nums[i]);
    }
    result.push_back(maxi);

    for (int i = k; i < nums.size(); i++)
    {
        if (maxi > nums[i - k])
        {
            maxi = max(maxi, nums[i]);
            result.push_back(maxi);
        }
        if (maxi == nums[i - k])
        {
            maxi = max(maxi, nums[i]);
            result.push_back(maxi);
        }
    }
    return result;
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

    vector<int> v = MinimumSubArray(nums, k);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}