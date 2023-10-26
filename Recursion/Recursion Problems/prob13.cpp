// combination sum using recursion
#include <bits/stdc++.h>

using namespace std;

void FindCombination(int index, int target, vector<int> &data, vector<vector<int>> &ans, vector<int> &ds)
{
    if (index == data.size())
    {

        if (target == 0)
            ans.push_back(ds);

        return;
    }

    // pick up the element
    if (data[index] <= target)
    {
        ds.push_back(data[index]);
        FindCombination(index, target - data[index], data, ans, ds);
        ds.pop_back(); // when we do the wrong picking of the element
    }
    FindCombination(index + 1, target, data, ans, ds);
}

int main()
{
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 7;

    FindCombination(0, target, data, ans, ds);
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