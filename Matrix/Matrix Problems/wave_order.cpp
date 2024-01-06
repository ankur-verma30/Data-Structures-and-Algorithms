#include <bits/stdc++.h>

using namespace std;

vector<int> WaveOrder(int A[][5], int m, int n)
{

    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                result.push_back(A[j][i]);
            }
        }
        else
        {
            for (int j = 0; j < m; j++)
            {
                result.push_back(A[j][i]);
            }
        }
    }
    return result;
}

int main()
{

    int A[5][5];

    cout << "Enter the elements of the matrix " << endl;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> A[i][j];
        }
    }

    // displaying input
    cout << "display the elements of the matrix " << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;

    cout<<"Displaying the results..."<<endl;

    vector<int> result = WaveOrder(A, 5, 5);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}