#include <bits/stdc++.h>

using namespace std;

void CombinationSum(vector<int>& arr, vector<int>& ans, vector<vector<int>>& ds, int index, int target) {
    if (index == arr.size()) {
        if (target == 0) {
            ds.push_back(ans);
        }
        return;
    }
    if (arr[index] <= target) {
        ans.push_back(arr[index]);
        CombinationSum(arr, ans, ds, index, target - arr[index]);
        ans.pop_back();
    }
    CombinationSum(arr, ans, ds, index + 1, target);
}

int main() {
    vector<vector<int>> ds;
    vector<int> ans;
    vector<int> arr {2, 3, 4, 7};

    CombinationSum(arr, ans, ds, 0, 7);

    for (int i = 0; i < ds.size(); i++) {
        for (int j = 0; j < ds[i].size(); j++) {
            cout << ds[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
