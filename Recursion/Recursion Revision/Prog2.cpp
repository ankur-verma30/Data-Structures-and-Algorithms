/*Writing the name n times using recursion*/

#include <bits/stdc++.h>

using namespace std;
void print(int i,int n)
{   
    if (i > n)
        return;
    cout << i << ". " <<"Ankur Verma"<< endl;
    print(i+1,n);
}

int main()
{
    int n;
    cout<<"How many times you want to print ";
    cin>>n;
    print(1,n);
    cout<<"Recursion completed."<<endl;
}