#include <iostream>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};
void changelength(struct Rectangle *p, int l)
{
    p->length = l; // for accessing the length value using pointer is done by arrow operator in structure;
}
int main()
{
    struct Rectangle r = {10, 20};
    changelength(&r, 20);
    cout << r.length;
    return 0;
}