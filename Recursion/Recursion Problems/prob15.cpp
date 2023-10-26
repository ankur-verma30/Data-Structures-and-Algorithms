// subset sum problem the possible sum can be formed from the given number of elements

#include <bits/stdc++.h>

using namespace std;

void SubsetSum(vector<int> &data, int index, int N, int sum, vector<int> &Subset)
{
    if (index == N)
    {
        Subset.push_back(sum);
        return;
    }
    // picking up the element
    SubsetSum(data, index + 1, N, sum + data[index], Subset);

    // do not picking up the element
    SubsetSum(data, index + 1, N, sum, Subset);
}

int main()
{

    vector<int> subset;
    vector<int> data{3, 2, 1};
    int N = data.size();
    SubsetSum(data, 0, N, 0, subset);
    sort(subset.begin(), subset.end());
    for (auto it : subset)
        cout << it << " ";
    cout << endl;
    return 0;
}