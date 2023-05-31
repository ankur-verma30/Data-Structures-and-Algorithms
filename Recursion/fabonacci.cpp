#include<iostream>
using namespace std;
//first doing recursively 
int fab(int n)
{ 
    if(n<=1)
    return n;
    return fab(n-2)+fab(n-1);
}
// doing itretively
// int fabo(int n)
// {
//     int t1=0,t2=1,t3=0;
//     if(n<=1)
//     return n;
//     if(n>1)
//     {
//     for(int i=2;i<=n;i++)
//     {
//         t3=t1+t2;
//         t1=t2;
//         t2=t3;
//     }
//     }
//     return t3;
// }
int main()
{
    cout<<"Fabonacci number is = "<<fab(10);
    return 0;
}