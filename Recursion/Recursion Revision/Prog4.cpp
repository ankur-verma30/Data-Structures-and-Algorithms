/*Print sum of first n natural numbers*/

#include <bits/stdc++.h>
using namespace std;

// Parameteriszed Recursion
void sum1(int i, int sum)
{
    if (i < 1){
        cout<< sum;
        return;
    }
    sum1(i - 1, sum + i);
    
    
}

// Functional Recursion
int sum2(int n)
{
    if (n == 0)
        return 0;
    return n + sum2(n - 1);
}

int main()
{
    int n;
    cout<<"Enter the number of elements ";
    cin >> n;
    cout << "sum of first n natural numbers  using parameterized recursion: ";
    sum1(n,0);
    int res2 = sum2(n);
    cout <<endl<< "Sum of first n natural numbers using functional recursion: " << res2 << endl;
    return 0;
}