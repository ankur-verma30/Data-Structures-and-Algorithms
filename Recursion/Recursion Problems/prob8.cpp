// print all the subsequences
#include <bits/stdc++.h>

using namespace std;

void print(int index, vector<int> &ds, int arr[], int n)
{
    if (index >= n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        if (ds.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }
        // take or pick the particular index inot the subsequence
        ds.push_back(arr[index]);
        print(index + 1, ds, arr, n);
        ds.pop_back();

        // not pick or not take condition this element is not added to your subsequence
        print(index + 1, ds, arr, n);
    }

    using namespace std;
    int main()
    {

        int arr[] = {3, 2, 1};
        int n = 3;
        vector<int> ds;
        print(0, ds, arr, n);
        return 0;
    }