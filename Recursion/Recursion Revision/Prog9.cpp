// Printing any one subsequence who sum is k

#include <bits/stdc++.h>

using namespace std;

bool solve(int index, vector<int> &ans, vector<int> &res, int sum, int curr)
{
    if (index == res.size())
    {
        if (curr == sum)
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            return true;
        }
        else
            return false;
    }
    ans.push_back(res[index]);
    curr += res[index];
    if (solve(index + 1, ans, res, sum, curr) == true)
        return true;
    curr -= res[index];
    ans.pop_back();
    if (solve(index + 1, ans, res, sum, curr) == true)
        return true;

    return false;
}

int main()
{
    vector<int> ans;
    vector<int> res{1, 2, 3, 1, 1};
    int sum = 5;
    solve(0, ans, res, sum, 0);
    return 0;
}