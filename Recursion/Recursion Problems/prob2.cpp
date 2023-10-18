// printing the number in reverse

#include <iostream>
using namespace std;

void print(int i, int n)
{
    if (n < i)
        return;
    cout << n << endl;
    print(i, n - 1);
    n--;
}

int main()
{
    int n;
    cin >> n;
    print(1, n);
    return 0;
}