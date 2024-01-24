/*Using the variable size sliding window
Problem statement is : Longest Subarray of sum k
*/
#include <bits/stdc++.h>

using namespace std;

int longestSubarrayLength(vector<int> &nums, int k)
{
    int len = nums.size();
    int mx = 0, sum = 0, i = 0, j = 0;

    while (j < len)
    {
        sum += nums[j];
        if (sum < k)
        {
            if (j < len)
                j++;
        }
        if (sum == k)
        {
            mx = max(mx, j - i + 1);
            j++;
        }

        if (sum > k)
        {
            while (sum > k)
            {
                sum -= nums[i];
                i++;
            }
            j++;
        }
    }
    return mx;
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
    cout << "Enter the sum  of the subarray " << endl;
    cin >> k;

    int result = longestSubarrayLength(nums, k);
    cout << "The length of the subarray " << result << endl;
    return 0;
}