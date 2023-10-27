// given an array nums that may contain duplicates return all possible subsets (the power set).

// The solution set must not contain duplicates subsets. Return the solution in any order
// nums={1,2,2}
// Output: [[].[1],[1,2],[1,2,2],[2],[2,2]]

#include <bits/stdc++.h>

using namespace std;

void findSubsets(int index, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds)
{
    //no need of the base cases
    ans.push_back(ds); // for the empty data value first will be empty
    for (int i = index; i < nums.size(); i++)
    {
        if (i != index && nums[i] == nums[i - 1]) // first condition means if the value is not picked for the first time and is equal then it means its the repitition and we will discard and move ahead
            continue;
        ds.push_back(nums[i]);
        findSubsets(i + 1, nums, ans, ds);
        ds.pop_back();
    }
}
int main()
{
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> nums{1, 2, 2, 2, 3, 3};
    sort(nums.begin(), nums.end());
    findSubsets(0, nums, ans, ds);
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