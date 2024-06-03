// Sum of subsets

#include <bits/stdc++.h>

using namespace std;
void SumOfSubsets(int index, vector<int> &arr, int sum, vector<int> &res)
{
    if (index == (int)arr.size())
    {
        res.push_back(sum);
        return;
    }
    SumOfSubsets(index + 1, arr, sum + arr[index], res);
    SumOfSubsets(index + 1, arr, sum, res);
}

int main()
{
    vector<int> arr{3, 1, 2};
    cout << "the sum of all the subsets are " << endl;
    vector<int> res;
    SumOfSubsets(0, arr, 0, res);
    sort(res.begin(), res.end());
    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;
}