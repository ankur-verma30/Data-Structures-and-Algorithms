/*First -ve integer in every window of size k*/
#include <bits/stdc++.h>

using namespace std;
vector<int> FirstNegative(vector<int> &a, int k)
{
    vector<int> result;
    int start = 0, end = 0;
    while (end < a.size())
    {
        if (end - start + 1 < k)
        {
            if (a[start] < 0)
                result.push_back(a[start]);
            end++;
        }
        if (end - start + 1 == k)
        {
            if (a[start] < 0)
                result.push_back(a[start]);
            start++;
            end++;
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

    vector<int> v = FirstNegative(nums, k);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}