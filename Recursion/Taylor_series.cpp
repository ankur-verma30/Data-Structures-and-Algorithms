#include<iostream>
using namespace std;
double e(int x,int n)
{
    static double p=1,f=1;
    double r;
    if(n==0)
    return 1;
    else
    r=e(x,n-1);
    p*=x;
    f*=n;
    return r+(p/f);
}
int main()
{
    int x,n;
    double result;
    cout<<"Enter the integral values of x"<<endl;
    cin>>x;
     cout<<"Enter the integral values of n"<<endl;
    cin>>n;
result=e(x,n);
cout<<"The reult of e power x to number of terms are = "<<result;
return 0;
}