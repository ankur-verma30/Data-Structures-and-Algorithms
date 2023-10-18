// using parameterized and functional recursion print the sum of n natural numbers
#include <iostream>

using namespace std;
// this is parameterized form
void Parasum(int i, int sum)
{
    if (i < 1)
    {
        cout << "sum is " << sum;
        return;
    }
    Parasum(i - 1, sum + i);
}

//functional recursion
int Funcsum(int n)
{

    if (n <= 0)
        return 0;
  
    return n + Funcsum(n - 1);
}
int main()
{

    int n;
    cin >> n;
    Parasum(n, 0);
    cout<<endl;
    cout<<"sum is "<<Funcsum(n);

    return 0;
}