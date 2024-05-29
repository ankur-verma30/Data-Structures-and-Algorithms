// Counting the number of subsequences which satisfies the given condition
// Printing any one subsequence who sum is k

#include <bits/stdc++.h>

using namespace std;

int solve(int index, vector<int> &ans, vector<int> &res, int sum, int curr)
{
    // when the curr is greater than sum
    // it is only possible when the array is strictly increasing
    if (curr > sum)
        return 0;
    if (index == res.size())
    {
        if (curr == sum)
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
            return 1;
        }
        else
            return 0;
    }
    ans.push_back(res[index]);
    curr += res[index];
    int l = solve(index + 1, ans, res, sum, curr);
    curr -= res[index];
    ans.pop_back();
    int r = solve(index + 1, ans, res, sum, curr);

    return l + r;
}

int main()
{
    vector<int> ans;
    vector<int> res{1, 2, 3, 1, 1};
    int sum = 5;
    int count = solve(0, ans, res, sum, 0);
    cout << "The total count of the subsequence is " << count;
    return 0;
}