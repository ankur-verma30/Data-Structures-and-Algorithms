#include <iostream>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};
int main()
{
    Rectangle r = {10, 15};
    cout << r.length << endl
         << r.breadth << endl;
    Rectangle *p = &r;
    cout << p->length << endl
         << p->breadth << endl;

    // using malloc funtion
    //  p=(struct Rectangle *)malloc(sizeof(struct Rectangle));//this is a type of creating object in heap using c language other method is
    p = new Rectangle; // same works as above code line it is used in c++
    p->length = 15;
    p->breadth = 13;
    cout << p->length << endl
         << p->breadth;
    return 0;
}