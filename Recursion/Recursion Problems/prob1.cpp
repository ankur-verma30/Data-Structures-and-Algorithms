// print the name n times using recursion
#include <iostream>

using namespace std;

void print(int i, int n)
{

    if (i > n)
        return;
    cout << "Ankur " << i << endl;
    print(i+1,n);
    i++;
}

int main()
{
    int n;
    cin >> n;
    print(1, n);
    return 0;
}