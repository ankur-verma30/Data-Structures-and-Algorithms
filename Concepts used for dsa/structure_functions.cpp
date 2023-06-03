#include <iostream>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};
void initialize(struct Rectangle *r1, int l, int b)
{
    r1->length = l;
    r1->breadth = b;
}
void changelength(struct Rectangle *p, int l)
{
    p->length = l; // for accessing the length value using pointer is done by arrow operator in structure;
}
int area(struct Rectangle &r1) // this is a call by reference method of passing structure as parameter
{
    r1.length++;
    return r1.length * r1.breadth;
}
int main()
{
    struct Rectangle r;
    initialize(&r, 10, 5);
    changelength(&r, 20);
    cout << "area of rectangle is = " << area(r);
    return 0;
}