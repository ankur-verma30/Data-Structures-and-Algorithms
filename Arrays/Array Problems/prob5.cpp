// left rotate the array by one place

#include <bits/stdc++.h>

using namespace std;

void LeftRotation(vector<int> &a)
{
    int temp = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        a[i - 1] = a[i];
    }
    a[a.size() - 1] = temp;
}

int main()
{
    vector<int> a;
    int N;
    int v;

    cout << "Enter the size of the array" << endl;
    cin >> N;

    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> v;
        a.push_back(v);
    }

    LeftRotation(a);

    cout << "Array after left rotation by one place: " << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
