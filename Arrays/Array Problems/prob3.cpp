// check if the array is sorted
#include <bits/stdc++.h>

using namespace std;
bool CheckSortedArray(vector<int> &a)
{
    bool result = true;
    bool result2 = true;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i - 1] > a[i])
        {
            result = false;
            break;
        }
    }
    // for
    for (int i = 1; i < a.size(); i++)
    {
        if (a[a.size() - i - 1] < a[a.size() - i])
        {
            result2 = false;
            break;
        }
    }
    return (result || result2);
}
int main()
{
    vector<int> a;
    int N;
    int v;
    cout << "Enter the size of the array" << endl;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> v;
        a.push_back(v);
    }
    cout << boolalpha;
    cout << "the array is sorted " << CheckSortedArray(a);
    return 0;
}