#include<iostream>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};
// int area(struct Rectangle r1)     //this is a call by value method of passing structure as parameter
// {
//     return r1.length*r1.breadth;
// }
int area(struct Rectangle &r1)   //this is a call by reference method of passing structure as parameter
{
    r1.length++;
    return r1.length*r1.breadth;
}
int main()
{
    struct Rectangle r={10,10};
    cout<<"area of rectangle is = "<<area(r);
    return 0;
}