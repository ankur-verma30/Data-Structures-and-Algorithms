#include<iostream>
using namespace std;
void fun1(int x)
{
    if(x>0)
    {
fun1(x-1);
cout<<"N ="<<x<<endl;
cout<<"Hello World"<<endl;
    }
}
int  main()
{
    int n=0;
    cout<<"Enter the number"<<endl;
    cin>>n;
    fun1(n);
    return 0;

}