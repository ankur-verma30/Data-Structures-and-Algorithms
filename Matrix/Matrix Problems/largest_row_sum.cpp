#include <bits/stdc++.h>

using namespace std;

int largestRowSum(int A[][3], int m, int n)
{
    int maxi = INT_MIN;
    int RowIndex = 0;

    for (int row = 0; row < m; row++)
    {
        int sum = 0;
        for (int col = 0; col < n; col++)
        {
            sum += A[row][col];
        }
        if (sum > maxi)
        {
            maxi = sum;
            RowIndex = row;
        }
    }
    cout << "The largest row sum is " << maxi << endl;
    return RowIndex;
}

int main()
{

    int A[3][3];
    // taking input
    cout << "Enter the elements of the matrix " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> A[i][j];
        }
    }
    // displaying input
    cout << "display the elements of the matrix " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    // Printing the largest row sum and its index
    int num= largestRowSum(A, 3, 3);
    cout << "the Index number of the row having largest sum is " <<num;

    return 0;
}
