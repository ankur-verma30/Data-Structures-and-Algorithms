#include<iostream>
using namespace std;
int main()
{ int i;
    char c[]="WELCOME";
    for(i=0;c[i]!='\0';i++)
    {
c[i]+=32;
    }
    cout<<"In lower case = "<<c;
    return 0;
}