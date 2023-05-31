#include<iostream>
// #include<stdlib.h>
using namespace std;
int main()

{
    int a=10;
    int &r=a;
    cout<<a<<endl<<r;
    int b=25;

    cout<<r<<endl<<b;
    return 0; }
