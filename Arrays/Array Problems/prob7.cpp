// move all the zeroes to the last
#include <bits/stdc++.h>

using namespace std;

// Time complexity will be O(2N)
// Space complexity will be O(N) at worst case
void MoveZeroesBruteForce(vector<int> &array)
{
    vector<int> temp;

    for (int i = 0; i < array.size(); i++)
        if (array[i] != 0)
            temp.push_back(array[i]);

    for (int i = 0; i < temp.size(); i++)
        array[i] = temp[i];

    for (int i = temp.size(); i < array.size(); i++)
        array[i] = 0;
}
void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// optimal solution
void RemoveDuplicatesUsingTwoPointers(vector<int> &left)
{
    int j = -1;
    for (int i = 0; i < left.size(); i++)
    {
        if (left[i] == 0)
        {
            j = i;
            break;
        }
    }
    for (int i = j + 1; i < left.size(); i++)
    {
        if (left[i] != 0)
        {
            swap(left[i], left[j]);
            j++;
        }
    }
}
int main()
{
    vector<int> left;
    int N;
    cout << "the size of the array " << endl;
    cin >> N;
    int a;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        left.push_back(a);
    }

    // MoveZeroesBruteForce(left);
    RemoveDuplicatesUsingTwoPointers(left);
    
    for (int i = 0; i < N; i++)
        cout << left[i] << " ";
    cout << endl;
    return 0;
}