// check whether the string is palindrome


#include<bits/stdc++.h>//contains all the header files

using namespace std;

bool palindrome(string &s, int i)
{
    if (i >= s.size() / 2)
        return true;
    if (s[i] != s[s.size() - 1 - i])
    return false;
    return palindrome(s, i + 1);
}

int main()
{
    string s;
    cin>>s;
    cout << boolalpha;
    cout << "the given string is palindrome " << palindrome(s, 0);
    return 0;
}