// Write the fabonacci number using multiple recursion calls

#include <bits/stdc++.h>

using namespace std;

int fabonacci(int n)
{
    if (n <= 1)
        return n;
    return fabonacci(n - 1) + fabonacci(n - 2);
}

int main()
{
    int n;
    cout << "Find the facbonacci number..." << endl;
    cin >> n;
    cout << n << "th place fabonaci number is : " << fabonacci(n) << endl;
    return 0;
}