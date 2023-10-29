// remove the duplicate from the array
#include <bits/stdc++.h>

using namespace std;
// Time Completxity is O(NlogN + N)
// Space Completxity is O(N)
void RemoveDuplicatesUsingSets(vector<int> &v)
{ // works for non sorted array and it will return the sorted array as set stores everything in the ascending order
    set<int> unique;
    for (int i = 0; i < v.size(); i++)
        unique.insert(v[i]);

    int index = 0;
    for (auto it : unique)
    {
        v[index] = it;
        index++;
    }

    v.resize(unique.size());
}

void RemoveDuplicatesUsingTwoPointer(vector<int> &v)
{
    int i = 0;
    for (int j = 1; j < v.size(); ++j)
    {
        if (v[i] != v[j])
        {
            v[i + 1] = v[j];
            i++;
        }
    }
    v.resize(i + 1);
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
    // RemoveDuplicatesUsingSets(a);
    RemoveDuplicatesUsingTwoPointer(a);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}