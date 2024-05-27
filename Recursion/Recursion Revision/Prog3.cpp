/*Print 1 to n using recusrion and backtracking*/

#include <bits/stdc++.h>
using namespace std;

void printUsingRecursion(int i, int n)
{
    if (i > n)
        return;

    cout << i << endl;
    printUsingRecursion(i + 1, n);
}

void printUsingBacktracking(int i, int n)
{
    if (i < 1)
        return;
    printUsingBacktracking(i - 1, n);
    cout << i << endl;
}

// print n to 1 using backtracking
void printUsingBacktracking2(int i, int n)
{
    if (i > n)
        return;
    printUsingBacktracking2(i + 1, n);
    cout << i << endl;
}

int main()
{
    int n;
    cin >> n;
    cout << "Print 1 to n using recusrion " << endl;
    printUsingRecursion(1, n);

    cout << "Print 1 to n using backtracking " << endl;
    printUsingBacktracking(n, n);

    cout << "Printing the reverse number using backtracking " << endl;
    printUsingBacktracking2(1, n);
}