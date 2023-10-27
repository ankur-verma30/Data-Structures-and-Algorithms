// find the largest element in the array
#include <bits/stdc++.h>

using namespace std;

int LargestElement(vector<int> &array)
{
    int largest = array[0];
    for (int i = 1; i < array.size(); i++)
    {
        if (array[i] > largest)
        {
            largest = array[i];
        }
    }
    return largest;
}

int main()
{
    vector<int> array;
    int N;
    cout << "Enter the size of the array" << endl;
    cin >> N;
    int a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        array.push_back(a);
    }

    cout << "the largest element of the array is " << LargestElement(array);
    return 0;
}