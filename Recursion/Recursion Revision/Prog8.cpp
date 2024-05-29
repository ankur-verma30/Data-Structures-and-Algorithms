// Printing the subsequences whose sum is k

#include <bits/stdc++.h>

using namespace std;

void solve(int index, vector<int> &ele, int sum, int curr, vector<int> &ans)
{
    if (index == ele.size())
    {
        if (sum == curr)
        {
            cout << "Printing subsequence " << endl;
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    curr += ele[index];
    ans.push_back(ele[index]);
    solve(index + 1, ele, sum, curr, ans);
    curr -= ele[index];
    ans.pop_back();
    solve(index + 1, ele, sum, curr, ans);
}

int main()
{
    vector<int> ans;
    vector<int> ele{1, 2, 1};
    int sum = 2;
    solve(0, ele, sum, 0, ans);
}