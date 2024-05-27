// Reverse the array using recursion

#include <bits/stdc++.h>

using namespace std;

// using two pointer recursion approach
void ReverseArray(vector<int> &a, int n, int l, int r)
{
    if (l >= r)
        return;
    int temp = a[l];
    a[l] = a[r];
    a[r] = temp;
    ReverseArray(a, n, l + 1, r - 1);
}

// using single pointer
void ReverseArray2(vector<int> &a, int n, int i)
{
    if (i >= n - i - 1)
        return;
    int temp = a[i];
    a[i] = a[n - i - 1];
    a[n - i - 1] = temp;
    ReverseArray2(a, n, i + 1);
}

int main()
{
    vector<int> a;
    int n;
    cout << "Enter the length of the array ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ch;
        cin >> ch;
        a.push_back(ch);
    }
    cout << "Array before reversing  " << endl;
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;
    ReverseArray(a, n, 0, n - 1);
    cout << "After reversing the array the array  using two pointer recursion approach is " << endl;
    for (auto it : a)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << "Reversing the array without using two pointer recursion approach " << endl;
    ReverseArray2(a, n, 0);
    cout << "After reversing the array the array without using two pointer recursion approach" << endl;
    for (auto it : a)
    {
        cout << it << " ";
    }
}