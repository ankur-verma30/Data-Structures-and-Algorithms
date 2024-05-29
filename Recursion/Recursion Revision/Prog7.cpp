// Creating all the subsequences

#include <bits/stdc++.h>

using namespace std;

void print(vector<int> &res)
{
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

void AllSubsequences(int index, vector<int> &res, vector<int> &ele, int n)
{
    if (index >= n)
    {
        print(res);
        return;
    }
    res.push_back(ele[index]);
    AllSubsequences(index + 1, res, ele, n);
    res.pop_back();
    AllSubsequences(index + 1, res, ele, n);
}

int main()
{
    vector<int> ele{1, 2, 3};
    vector<int> res;
    AllSubsequences(0, res, ele, 3);
}