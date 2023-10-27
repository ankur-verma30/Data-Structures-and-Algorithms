/* given an array nums of distinct intergers return all the possible permutations. You can return the answer in any order
input: nums=[1,2,3]
output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]] these are all the possible permutations of the given array*/
// Using the extra space of frequency array for the mapping of the element
#include <bits/stdc++.h>

using namespace std;

void findValidPermutation(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[])
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i]) // if it is unmarked pick that
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            findValidPermutation(ds, nums, ans, freq);
            freq[i] = 0; // now then unmark it
            ds.pop_back();
        }
    }
}

int main()
{
    vector<int> ds;
    vector<vector<int>> ans;
    vector<int> nums{1, 2, 3, 4};
    int freq[nums.size()];
    for (int i = 0; i < nums.size(); i++)
        freq[i] = 0;
    findValidPermutation(ds, nums, ans, freq);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}