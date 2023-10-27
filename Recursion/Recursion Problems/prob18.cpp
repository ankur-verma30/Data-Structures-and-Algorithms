/* given an array nums of distinct intergers return all the possible permutations. You can return the answer in any order
input: nums=[1,2,3]
output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]] these are all the possible permutations of the given array*/
// Without Using the extra space of frequency array for the mapping of the element
#include <bits/stdc++.h>

using namespace std;
void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
void findValidPermutation(int index, vector<int> &nums, vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        findValidPermutation(index + 1, nums, ans);
        swap(nums[index], nums[i]);
    }
}
//saving lots of space in this approach
int main()
{

    vector<vector<int>> ans;
    vector<int> nums{1, 2, 3, 4};

    findValidPermutation(0, nums, ans);

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