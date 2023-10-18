// printing numbers using backtracking]
#include <iostream>

using namespace std;

void print(int i, int n)
{
    if (i < 1)
        return;
        // cout<<i<<endl;//for reverse using backtracking put the cout befor the function call
    print(i - 1, n);
    cout << i << endl;
}
int main()
{
    int n;
    cin >> n;
    print(n, n);
}