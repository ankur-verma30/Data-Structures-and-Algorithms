// find the second largest element in the array
#include <bits/stdc++.h>

using namespace std;
// BETTER APPROACH of O(2N)
int SecondLargeElement(vector<int> &a)
{
    int largeElement = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] > largeElement)
        {
            largeElement = a[i];
        }
    }
    int secondLargeElement = INT_MIN;
    for (int i = 0; i < a.size(); i++)
    {
        if (secondLargeElement < a[i] && a[i] != largeElement)
        {
            secondLargeElement = a[i];
        }
    }
    return secondLargeElement;
}

// OPTIMISED PROBLEM  Time Complexity is O(N)
int SecondLargeElementVersion2(vector<int> &a)
{
    int largeElement = a[0];
    int secondLargeElement = INT_MIN;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] > largeElement)
        {
            secondLargeElement = largeElement;
            largeElement = a[i];
        }
        else if (a[i] < largeElement && a[i] > secondLargeElement)
        {
            secondLargeElement = a[i];
        }
    }
    return secondLargeElement;
}
int main()
{
    vector<int> a;
    int N;
    cout << "the size of the array is " << endl;
    cin >> N;
    int x;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    // cout << "the second largest element in the array is " << SecondLargeElement(a);
    cout << "the second largest element in the array is " << SecondLargeElementVersion2(a);
    return 0;
}