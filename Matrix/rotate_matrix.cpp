#include <iostream>
#define R 4
#define C 4

using namespace std;

void rotateMatrix(int m, int n, int matrix[R][C])
{
    int row = 0;
    int col = 0;
    int prev, curr;
    // row=starting row  row=starting row index col=starting column index
    // m= ending row index n= ending column index

    while (row < m && col < n)
    {
        if (row + 1 == m || col + 1 == n) // only one row or column rotation not possible
            break;

        // store the first element of next row,this element whill replace first element of first element of current row
        prev = matrix[row + 1][col];

        // move first element of first row from the remaining rows
        for (int i = col; i < n; i++)
        {
            curr = matrix[row][i];
            matrix[row][i] = prev;
            prev = curr;
        }
        row++;

        // move the last column from the remaining columns
        for (int i = row; i < m; i++)
        {
            curr = matrix[i][n - 1];
            matrix[i][n - 1] = prev;
            prev = curr;
        }
        n--;

        // move elements of last row from the remaining rows
        if (row < m)
        {
            for (int i = n - 1; i >= col; i--)
            {
                curr = matrix[m - 1][i];
                matrix[m - 1][i] = prev;
                prev = curr;
            }
        }
        m--;
        // move elements of first column from the remaining columns
        if (col < n)
        {
            for (int i = m - 1; i >= row; i--)
            {
                curr = matrix[i][col];
                matrix[i][col] = prev;
                prev = curr;
            }
        }
        col++;
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << matrix[i][j] <<"  ";
        }
        cout << endl;
    }
}

int main()
{

    int a[R][C] = {{1, 2, 3, 4}, 
                   {5, 6, 7, 8}, 
                   {9, 10, 11, 12}, 
                   {12, 13, 14, 15}};
    rotateMatrix(R, C, a);
    return 0;
}