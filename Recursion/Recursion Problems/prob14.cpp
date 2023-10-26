// Given the collection of numbers and a target number, find all unique numbers in numbers where the numbers sum to target
// Each number in numbers may only be used once in the combination.

#include <bits/stdc++.h>

using namespace std;
void FindCombination(int index, int target, vector<int> &data, vector<vector<int>> &ans, vector<int> &ds)
{
    if(target==0){
        ans.push_back(ds);
        return;

    }
    for(int i=index;i<data.size();i++){
        if(index<i && data[i]==data[i-1])
        continue;
        if(data[i]>target)
        break;
        ds.push_back(data[i]);
        FindCombination(index+1,target-data[i],data,ans,ds);
        ds.pop_back();
    }
}

int main()
{
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> data{1, 2,3,3,4,2,3,3,2, 3, 5,5, 6,6,6, 7,7, 8, 9};
    int target = 7;
    sort(data.begin(), data.end());//the array must be sorted

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