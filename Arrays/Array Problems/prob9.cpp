// two sum is equal to target
#include <bits/stdc++.h>

using namespace std;
// Better approach
string TwoSum(int N, vector<int> &array, int target)
{
    map<int, int> m;
    for (int i = 0; i < N; i++)
    {
        int a = array[i];
        int more = target - a;
        if (m.find(more) != m.end())
        {
            return "YES";
        }
        m[a] = i;
        
    }
    return "NO";
}

    int main()
    {
        int N;
        vector<int> array;
        int a;
        cout << "Enter the size of the array" << endl;
        cin >> N;
        cout<<"Enter the elements of the array" << endl;
        for (int i = 0; i < N; i++)
        {
            cin >> a;
            array.push_back(a);
        }
        int target;
        cout << "Enter the value of the target" << endl;
        cin >> target;
        cout << "The sum exist " << TwoSum(N, array, target) << endl;
        return 0;
    }
